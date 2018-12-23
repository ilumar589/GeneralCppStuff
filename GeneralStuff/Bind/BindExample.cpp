#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

namespace BindExample
{
	int add(int a, int b, int c)
	{
		cout << a << ", " << b << ", " << c << endl;
		return a + b + c;
	}

	void bindAdd()
	{
		auto calculate = bind(add, 3, 4, 5);

		cout << calculate() << endl;
	}
}