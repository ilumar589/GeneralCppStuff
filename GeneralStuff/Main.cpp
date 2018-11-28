#include <iostream>
#include <string>

#include "BasicExceptions.h"

using namespace std;

int main()
{
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
	

	return 0;
}