#include <iostream>
#include <string>
#include <fstream>

#include "BasicExceptions.h"
#include "TextFiles/TextFiles.h"
#include "TestClassInterdependency/Interdependency.h"
#include "ClassDefinitions/ClassDefinitions.h"
#include "ClassDefinitions/RingBuffer.h"
#include "Bind/BindExample.h"
#include "AutoPointerExample.h"


using namespace std;

void UseRingBuffer()
{
	Ring<string> Buffer{ 3 };

	Buffer.Add("one");
	Buffer.Add("two");
	Buffer.Add("three");
	Buffer.Add("four");

	// C++ 98 style
	for (Ring<string>::Iterator It = Buffer.begin(); It != Buffer.end(); It++)
	{
		cout << *It << endl;
	}

	// C++ 11 style
	for (auto Buff : Buffer)
	{
		cout << Buff << endl;
	}
}

void needToInvestigate()
{
	A a{ 1, "a class" };

	B *b = new B{ a };

	// what happens to the non pointer data member inside the B class when I call delete on pointer b ?
	delete b;
}

void testAssignementsAndInitilization()
{
	TestConstructorsAndOperators t;
	TestConstructorsAndOperators t2{20, "T2 name"};

	t = t2;

	TestConstructorsAndOperators t3{ t };
}

void takeReference(string& aString)
{
	cout << aString << endl;
}

A retRight() {
	A a_move{ 2, "a second class" };
	return  a_move;
}

void testInterdependancy()
{
	testAssignementsAndInitilization();

	A a{ 1, "a class" };

	B b{ a };


	B b_move{ retRight() };

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
	AutoPointerExampleNs::executeExample();

	BindExample::bindAdd();

	UseRingBuffer();

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