#pragma once

namespace CaveOfProgramming
{
	class ComplexNumber
	{

	private:
		double Real;
		double Imaginary;

	public:
		ComplexNumber();

		ComplexNumber(const ComplexNumber &other);

		~ComplexNumber();
	};
}



