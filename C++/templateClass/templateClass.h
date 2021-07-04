#pragma once


#ifndef A_H
#define A_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;


/// \brief ǰ�YҪ��
#define MPC_CLASS(_name)    CVX_Mpc_ ## _name
#define MPC_STRUCT(_name)  stVX_MPC_ ## _name
/// \brief �ṹ�����ȫ���� 8 �ֽڶ���
#define MPC_CLASS_DEF(_name)   class  /*__attribute__((aligned(8)))*/ MPC_CLASS(_name)
#define MPC_STRUCT_DEF(_name)  struct /*__attribute__((aligned(8)))*/ MPC_STRUCT(_name)
/// \brief �ӿ����ʶ
#define MPC_INTERFACE_CLASS  /*__attribute__((visibility("default"), aligned(8)))*/
/// \brief �ӿ��ඨ��
#define MPC_INTERFACE_CLASS_DEF(_name)  class MPC_INTERFACE_CLASS MPC_CLASS(_name)

/// \brief ����Ա���ε��ø��Ե� �������� �� ������ֵ
#define MPC_DEFAULT_COPY_AND_ASSIGN(_name)  _name(const _name &) = default; _name & operator=(const _name &) = default;
/// \brief ������ �������� �� ������ֵ
#define MPC_DELETE_COPY_AND_ASSIGN(_name)   _name(const _name &) = delete;  _name & operator=(const _name &) = delete;


/**
 * @brief runtime base class
 * @warning you'd better call M_SetClassName() in derived class's constructor
 */
MPC_INTERFACE_CLASS_DEF(Class)
{
public:
	MPC_CLASS(Class)() = default;

	virtual
		~MPC_CLASS(Class)() noexcept = default;

	MPC_DEFAULT_COPY_AND_ASSIGN(MPC_CLASS(Class))

		MPC_CLASS(Class)(MPC_CLASS(Class) && _src) noexcept : M_this_class_name(std::move(_src.M_this_class_name)) {}

	MPC_CLASS(Class)&
		operator=(MPC_CLASS(Class) && _rhs) noexcept
	{
		if (&_rhs != this)
		{
			M_this_class_name = std::move(_rhs.M_this_class_name);
		}
		return *this;
	}

	const std::string&
		ClassName() const { return M_this_class_name; }

protected:
	void
		M_SetClassName(const std::string & _name) { M_this_class_name = _name; }

private:
	std::string M_this_class_name;
};

/**
 * @brief singleton class base
 * @tparam Derived ����
 * @warning ָ�� -fvisibility=hidden �Ż�����Ҫ�ӵ�����ʶ����ȫ�ֵ���������ģʽ��Ҳ����ӵ�����ʶ�������ʹ���˻�Ϊģ��ֲ��ĵ�����
 */
template<typename Derived>
MPC_INTERFACE_CLASS_DEF(Singleton) : virtual public MPC_CLASS(Class)
{
public:
	MPC_DELETE_COPY_AND_ASSIGN(MPC_CLASS(Singleton))

		/// \brief ��ȡʵ�������Ψһ��ʽ
		Derived&
		Inst() noexcept
	{
		static Derived _inst;
		return _inst;
	}

protected:
	MPC_CLASS(Singleton)() = default;
};


/////////////////////////////////

MPC_CLASS_DEF(Test) : public MPC_CLASS(Class)
{
public:
	explicit
		MPC_CLASS(Test)(std::string _name) : m_strName(std::move(_name)), m_uiIdx(0)
	{
		M_SetClassName("Test");
		
	}

	~MPC_CLASS(Test)() noexcept override
	{
		
	}

	template<typename Callable, typename ... Args>
	void
		RunOnce(const std::string & _name, Callable & _func, const Args &...args)
	{
		++m_uiIdx;

		try
		{
			auto bOk = _func(args...);
			
		}
		catch (const std::exception& ex)
		{
			
			return;
		}
	}

private:
	const std::string m_strName;
	uint m_uiIdx;
};















#endif // A_H
