#include <iostream>
#include <string>
#include <fstream>

#include "BasicExceptions.h"
#include "TextFiles/TextFiles.h"

using namespace std;

void takeReference(string& aString)
{
	cout << aString << endl;
}

int main()
{

	workWithFiles();

	try
	{
		TestCustomException customException;
		customException.goesWrong();
	}
	catch (MyException& e)
	{
		cout << e.what();
	}

	try
	{
		CanGoWrong wrong;
	}
	catch (bad_alloc& e)
	{
		cout << "Caught exception: " << e.what();
	}

	string aStringOnTheStack = string{ "A string on the stack!!!!" };

	string* aStringOnTheHeap = new string{ "A string on the heap!!!" };

	string anotherStringOnTheStack = string{ "Another string on the stack!!!!" };

	string* pointerToAStringOnTheStack = &anotherStringOnTheStack;

	takeReference(aStringOnTheStack);
	takeReference(*aStringOnTheHeap);
	takeReference(*pointerToAStringOnTheStack);

	try
	{
		mightGoWrong();
	}
	catch (char const* e)
	{
		cout << "Error code: " << e << endl;
	}
	catch (string& e)
	{
		cout << "String error message: " << e << endl;
	}
	
	// release memory and set pointers to null addresses
	delete aStringOnTheHeap;
	aStringOnTheHeap = nullptr;
	pointerToAStringOnTheStack = nullptr;

	return 0;
}