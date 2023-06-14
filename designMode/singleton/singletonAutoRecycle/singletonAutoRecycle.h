
#include <mutex>

class Singleton
{
private:
    Singleton()=default;
    ~Singleton()=default;
    Singleton(const Singleton&) = default;
    Singleton& operator=(const Singleton&) = default;
    
public:
    struct GC
    {
        ~GC()
        {
            if(Singleton::m_pInstance)
            {
                delete Singleton::m_pInstance;
                Singleton::m_pInstance = nullptr;
                std::cout << __FUNCTION__ << std::endl;
            }
        }
    };

public:
    static Singleton* Get()
    {
        static std::mutex mtx;
        static GC gc;

        if(nullptr == m_pInstance)
        {
            std::unique_lock<std::mutex> lk(mtx);
            if(nullptr == m_pInstance)
            {
                m_pInstance = new Singleton();
            }
        }

        return m_pInstance;
    }

private:
    static Singleton* m_pInstance;
};

Singleton* Singleton::m_pInstance = nullptr;

