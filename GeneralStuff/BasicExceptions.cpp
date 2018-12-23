#include <string>
#include "BasicExceptions.h"

void mightGoWrong()
{
	bool error1 = false;
	bool error2 = true;

	if (error1)
	{
		throw "Something went wrong";
	}

	if (error2)
	{
		throw std::string{ "Something else went wrong." };
	}
}

CanGoWrong::CanGoWrong()
{
	char* pMemory = new char[9999];
	delete[] pMemory;
}

CanGoWrong::~CanGoWrong()
{
}

const char * MyException::what() const noexcept
{
	return "Custom Exception"; // this has to be on the heap (so I guess the compiler does it), otherwise we return a pointer to already cleared memory
}

void TestCustomException::goesWrong()
{
	throw MyException{};
}
