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
	return "Custom Exception";
}

void TestCustomException::goesWrong()
{
	throw MyException{};
}
