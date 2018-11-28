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
		//delete aStringOnTheHeap;
	}
	catch (string& e)
	{
		cout << "String error message: " << e << endl;
		//delete aStringOnTheHeap; it seams that when catchig an exception memory cleaning is done automatically, though I don't know to what extent 
	}
	
	delete aStringOnTheHeap;
	return 0;
}