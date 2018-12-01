#include <iostream>
#include <string>
#include <fstream>

#include "TextFiles.h"

using namespace std;

void workWithFiles()
{
	ofstream outFile;

	string outputFileName{ "Text.txt" };

	outFile.open(outputFileName);

	if (outFile.is_open())
	{
		outFile << "Hello there" << endl;
		outFile << 123 << endl;
		outFile.close();
	}
	else
	{
		cout << "Could not open file: " << outputFileName << endl;
	}
}

void readPopulation()
{
	string fileName{ "Population.txt" };
	ifstream input;

	input.open(fileName);

	if (!input.is_open())
	{
		return;
	}

	string line;

	getline(input, line, ':');

	int population;

	input >> population;

	cout << "Country name: " << line << " with population " << population;
}
