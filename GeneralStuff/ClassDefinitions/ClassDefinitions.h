#pragma once

#include <iostream>
#include <string>

class TestConstructorsAndOperators
{

private:
	int aNumber;
	std::string aName;

public:
	TestConstructorsAndOperators() : aNumber(0), aName("") {}

	TestConstructorsAndOperators(int aNumber, const std::string& aName) : aName(aName), aNumber(aNumber) {}

	TestConstructorsAndOperators(const TestConstructorsAndOperators& other) : aNumber(other.aNumber), aName(other.aName)
	{
		std::cout << "Copy constructor initialized" << std::endl;
	}

	const TestConstructorsAndOperators& operator=(const TestConstructorsAndOperators& other)
	{
		std::cout << "= operator initialized" << std::endl;

		aNumber = other.aNumber;
		aName = other.aName;

		return *this;
	}
};