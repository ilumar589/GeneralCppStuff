#include <iostream>
#include <string>
#include <fstream>

#include "BasicExceptions.h"
#include "TextFiles/TextFiles.h"
#include "TestClassInterdependency/Interdependency.h"

using namespace std;

void takeReference(string& aString)
{
	cout << aString << endl;
}

void testInterdependancy()
{
	A a{ 1, "a class" };

	B b{ a };

	cout << "Original dependency -->" << "Id: " << a.GetId() << " ;Name: " << a.GetName() << endl;

	b.GetDependancy().SetId(2);

	string aNewName{ "a new name" };

	b.GetDependancy().SetName(aNewName);

	cout << "Dependency id: " << b.GetDependancy().GetId() << " ; Dependency name: " << b.GetDependancy().GetName() << endl;

	cout << "Original dependency after changes -->" << "Id: " << a.GetId() << " ;Name: " << a.GetName() << endl;

	// use of pointer

	cout << "----- POINTER USE DELIMITER-----" << endl;

	A a2{ 1, "a class" };

	C c{ &a2 };

	cout << "Original dependency -->" << "Id: " << a2.GetId() << " ;Name: " << a2.GetName() << endl;

	c.GetDependancy()->SetId(2);

	string aNewName2{ "a new name" };

	c.GetDependancy()->SetName(aNewName2);

	cout << "Dependency id: " << c.GetDependancy()->GetId() << " ; Dependency name: " << c.GetDependancy()->GetName() << endl;

	cout << "Original dependency after changes -->" << "Id: " << a2.GetId() << " ;Name: " << a2.GetName() << endl;


}

int main()
{

	testInterdependancy();

	readPopulation();

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