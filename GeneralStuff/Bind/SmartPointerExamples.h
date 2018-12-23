#pragma once

#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	Test()
	{
		cout << "created" << endl;
	}

	void greet()
	{
		cout << "Hello" << endl;
	}

	~Test()
	{
		cout << "destroyed" << endl;
	}
};

void testSmartPointers()
{
	unique_ptr<int> pTest(new int);

	cout << "Finished " << endl;
}