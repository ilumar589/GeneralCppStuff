#include <iostream>
#include <string>

#include "BasicExceptions.h"

using namespace std;

void takeReference(string& aString)
{
	cout << aString << endl;
}

int main()
{

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

	takeReference(aStringOnTheStack);
	takeReference(*aStringOnTheHeap);

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
	
	delete aStringOnTheHeap;
	return 0;
}