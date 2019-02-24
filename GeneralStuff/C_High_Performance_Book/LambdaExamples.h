#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <functional>

namespace LambdaExmpleNs {
	void declaringAndPassingAFunc() {
		const auto vals = std::vector<int>{ 1, 2, 3, 4 };

		const int three = 3;
		const int numThrees = std::count(vals.begin(), vals.end(), three);

		auto isAboveThree = [](int v) {return v > 3; };
		const int numThrees = std::count(vals.begin(), vals.end(), isAboveThree);
	}

	int capturingExternalValues(const std::vector<int>& vals, int th) {
		auto isAbove = [th](int v) {return v > th; }; // this was copied but we can also pass it by value &th
		return std::count(vals.begin(), vals.end(), isAbove);
	}

	// Lambdas are created with class syntax behind the scenes

	// A corresponding class to the lambda we just used
	class IsAbove {
	private:
		int th{};
	public:
		IsAbove(int th) : th{th} {}

		bool operator()(int v) const {
			return v > th;
		}
	};

	void initializingVariablesInCapture() {
		auto func = [values = std::list<int>{ 4, 2 }]() {
			for (auto val : values) {
				std::cout << val << std::endl;
			}
		};

		func();
	}
	//In order to allow the lambda to mutate its members, we need to specify mutable when
	//declaring the lambda.The mutable modifier on a lambda function works like the inverse
	//for a const modifier for a regular class member function; in contrast to a class member
	//function, a lambda function is const by default, and therefore a mutating lambda must be
	//explicitly specified :
	void lambdaThatMutates() {
		// we have the option to mutate the copy in which we have to specifically declare the mutable keyword
		// [v]() mutable {} - now we can change the capured value inside the lambda but the changes

		// on the other hand we can just capture by reference but we change the captured variable inside the 
		// lambda then those changes will be seen outside it as well. no mutable keyword is required
		// [&v]() {}
	}

	void captureAll() {
		//auto b = 1.0f;
		// Capture all variables by copy
		//auto lambda_0 = [=]() { std::cout << a << b << m_; };
		// Capture all variables by reference
		//auto lambda_1 = [&]() { std::cout << a << b << m_; };
		// Capture member variables by reference
		//auto lambda_2 = [this]() { std::cout << m_; };
		// Capture member variables by copy
		//auto lambda_3 = [*this]() { std::cout << m_; };

		//Note that using[=] does not mean that all variables in the scope are copied into the
		//lambda, only the variables actually utilized are copied.
	}

	void definingStdFunction() {
		// A std::function returning a bool and having an int and a std::string as parameters is defined as following
		auto func = std::function<bool(int, std::string)>{};
	}


	class Button {
	private:
		std::function<void(void)> m_onClick{};

	public:
		Button(std::function<void(void)> click) : m_onClick {click} {}

		void onClick() const { m_onClick(); }
	};

	std::vector<Button> makeButtons() {
		Button beepButton{ [beepCount = 0]() mutable {
			std::cout << "Beep:" << beepCount << "! ";
			++beepCount;
		} };

		Button bopButton{ []() {
			std::cout << "Bop. ";
		} };

		Button silentButton{ []() {} };

		auto buttons = std::vector<Button>{
			beepButton,
			bopButton,
			silentButton
		};

		return buttons;
	}

	void executeButtons() {
		auto buttons = makeButtons();
		for (const auto& button : buttons) {
			button.onClick();
		}
	}
}