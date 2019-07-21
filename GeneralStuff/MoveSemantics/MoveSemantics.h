#pragma once

#include <memory>

namespace MoveSemantics
{
	class Test
	{
	private:
		static const int SIZE = 100;

		int * m_Buffer{ nullptr };
	public:
		Test() 
		{
			m_Buffer = new int[SIZE] {};
		}

		// copy constructor
		Test(const Test & Other)
		{
			*this = Other;
		}

		// copy operator
		Test &operator=(const Test & Other)
		{
			m_Buffer = new int[SIZE] {};

			memcpy(m_Buffer, Other.m_Buffer, sizeof(int) * SIZE);

			return *this;
		}

		// move constructor
		Test(Test && Other) noexcept
		{
			// steal the resource
			// point m_Buffer to Other.m_Buffer
			m_Buffer = Other.m_Buffer;

			// point Other.m_Buffer to an empty address so that when it's destroyed t doesn't release the previously stolen memory
			Other.m_Buffer = nullptr;
		}

		Test &operator=(Test && Other) noexcept
		{
			// we need to take into account here that our current object has already allocated memory and we need to free it
			delete[] m_Buffer;

			m_Buffer = Other.m_Buffer;
			Other.m_Buffer = nullptr;
		}

		~Test()
		{
			if (m_Buffer != nullptr)
			{
				delete[] m_Buffer;
			}
		}

		void Empty() {}
	};

	Test ReturnTest()
	{
		return Test();
	}


	// example of extending the lifetime of a returned value
	void ExtendLifetime()
	{
		// C++98 standard had lvalues defined as any value that you can take the address of
		// Example:
		Test l_Test_LValue;
		Test * address_Test_LValue = &l_Test_LValue;
		Test * address_From_Function_Test_LValue = &ReturnTest(); // this does not work in C++98 standard

		Test &ExtendTestValueLife = l_Test_LValue; // this would extend the l_Test_LValue variable's lifetime if it were the case
		const Test &ExtendTestValueLife2 = ReturnTest(); // in order to extend the lifetime of an object returned through an rvalue we have to define
		                                                 // a constant variable

		// Another thing about this syntax is that it shows that you can point a variable from the stack
		// to another variable from the stack without needing a pointer to reference it's memory

		Test val1;
		Test &val2 = val1; // now val1 and val2 are pointing to the same address on the stack and we didn't have to declare a pointer

		// Thing is that doing stuff like this isn't always safe like in rust where you get notified at compile time
		// If val1's memory is released and then we try to use val2 I'm guessing we get an access violation crash or if
		// anything else took that memory space from val1 the using val2 afterwards will cause unexpected behavior
		// Example:
		Test * val3;

		{
			Test val4;
			val3 = &val4;
		}

		val3->Empty();
	}

	void Check(const Test & t)
	{
		// lvalue
	}

	void Check(Test && t)
	{
		// rvalue
	}

	// example of C++11's rvalue references
	void ExampleOfRValueReferences()
	{
		// we can get the address of the tmp value returned by a function (rvalue) like previous shown
		Test * address_Of_RValue = &ReturnTest(); // don't know if this extends the lifetime of the tmp return value. I'm guessing not

		Test && extend_RValue = ReturnTest();

	}
}