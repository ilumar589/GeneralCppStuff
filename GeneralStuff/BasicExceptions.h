#pragma once

#include <exception>

void mightGoWrong();

class CanGoWrong
{
public:
	CanGoWrong();
	~CanGoWrong();

private:

};

class MyException : std::exception
{
public:
	virtual const char* what() const noexcept;
};

class TestCustomException
{
public:
	void goesWrong();
};
