
#pragma once

#include <list>
#include <set>
#include <mutex>
#include <condition_variable>
#include <atomic>

/**
 * @brief 
 * 
 * @tparam Container 
 * @tparam Container::value_type 
 * @param _container 
 */

template<typename Container, typename T = typename Container::value_type>
void
printContainer(const Container &_container)
{
    auto itor = _container.begin();
    for(; itor!=_container.end(); ++itor)
    {
        std::cout << *itor<< " ";
    }
    std::cout << std::endl;
}

/**
 * @brief 
 * 
 * @tparam Container 
 * @tparam Container::value_type 
 * @param _container 
 * @param _size 
 * @param _t 
 */

template<typename Container, typename T = typename Container::value_type>
void
EnsureContainerSize(Container &_container, size_t _size, const T &_t = T{})
{
    for(auto i = _container.size(); i<_size; ++i)
    {
        _container.emplace_back(_t);
    }
}

/**
 * @brief 比较两个容器是否相等，按顺序依次比较
 * 
 * @tparam Container 
 * @param _l 
 * @param _r 
 * @return true 仅在元素个数和顺序均相等时返回true
 * @return false 
 */

template<typename Container>
bool
IsEqualContainer(const Container &_l, const Container &_r)
{
    if(_l.size() != _r.size())
        return false;

    auto _iterR = _r.cbegin();
    for(auto _iterL = _l.cbegin(); _iterL != _l.cend(); ++_iterL, ++_iterR++)
    {
        if(*_iterL != *_iterR)
            return false;
    }    
    return true;
}

/**
 * @brief 检查某个元素是否已经包含在容器内部
 * 
 * @tparam Container 
 * @tparam Container::value_type 
 * @param _container 
 * @param _t 
 * @return true 
 * @return false 
 */

template<typename Container, typename T = typename Container::value_type>
bool
InContainer(const Container &_container, const T &_t)
{
    for(const auto &_i: _container)
    {
        if(_i == _t)
            return true;
    }
    return false;
}

template<typename Container>
class SafeContainer
{
public:
    using value_type = typename Container::value_type;
    SafeContainer() = default;

    virtual
    ~SafeContainer() = default;

    bool
    Empty() noexcept
    {
        std::unique_lock<std::mutex> lk(m_mutex);
        return m_container.empty();
    }

    size_t
    Size() noexcept
    {
        SafeLock _sl(m_mutex);
        return m_container.size();
    }

    void
    Clear()
    {
        SafeLock _sl(m_mutex);
        m_container.clear();
    }

    void PushBack(const value_type &_value) noexcept
    {
        SafeLock _sl(m_mutex);
        m_container.push_back(_value);
    }

    void
    PushBackMultiple(const Container &_values) noexcept
    {
        SafeLock _sl(m_mutex);
        for(const auto &_value: _values)
        {
            m_container.push_back(_value);
        }
    }

    value_type
    PopFront()
    {
        SafeLock _sl(m_mutex);
        if(m_container.empty())
            return;
        auto _value = m_container.front();
        m_container.pop_front();
    }

    Container
    PopAll() noexcept
    {
        Container _container;
        SafeLock _sl(m_mutex);
        std::swap(_container, m_container);
    }

    const Container&
    GetContainer()
    {
        return m_container;
    }


protected:
    using Mutex = std::mutex;
    using SafeLock = std::unique_lock<std::mutex>;

    Container m_container;
    Mutex m_mutex;
};

/**
 * @brief 
 * 
 * @tparam Container 
 */

template<typename Container>
class SafeContainerExtra : public SafeContainer<Container>
{
public:
    using value_type = typename SafeContainer<Container>::value_type;
    
    SafeContainerExtra():m_bStop(false) {}

    void
    PushBack(const value_type &_value) noexcept override
    {
        SafeLock _sl(SafeContainer<Container>::m_mutex);
        m_cond.notify_one();
    }

    bool
    PopFront_Noexcept(value_type &_value) noexcept
    {
        if(m_bStop)
            return false;
        auto &_container = SafeContainer<Container>::m_container;
        SafeLock _sl(SafeContainer<Container>::m_mutex);
        if(_container.empty())
        {
            const static auto _timeout = std::chrono::seconds{5};
            do
            {
                m_cond.wait_for(SafeContainer<Container>::m_mutex, _timeout);
                if(m_bStop)
                    return false;
            } while (_container.empty());
        }
        _value = _container.front();
        _container.pop_front();
        return true;
    }

    void
    MarkStop() noexcept
    {
        m_bStop.store(true);
        SafeLock _sl(SafeContainer<Container>::m_mutex);
        m_cond.notify_all();
    }


protected:
    using SafeLock = std::unique_lock<std::mutex>;
    using Condition = std::condition_variable_any;

    std::atomic_bool m_bStop;
    Condition m_cond;
};

template<typename T>
class SafeSet final
{
public:
    SafeSet() = default;

    void
    Insert(const T &t) noexcept
    {
        SafeLock _sl(m_mutex);
        m_set.insert(t);
    }

    void
    Erase(const T &t) noexcept
    {
        SafeLock _sl(m_mutex);
        auto iter = m_set.find(t);
        if(iter!=m_set.end())
        {
            m_set.erase(iter);
        }
    }

    bool
    IsExist(const T &t) noexcept
    {
        SafeLock _sl(m_mutex);
        auto bExist = ( m_set.find(t) != m_set.end() );
        return bExist;
    }

    size_t
    Size() noexcept
    {
        SafeLock _sl(m_mutex);
        return m_set.size();
    }


protected:
    using Mutex = std::mutex;
    using SafeLock = std::unique_lock<std::mutex>;

    std::set<T> m_set;
    Mutex m_mutex; 
};