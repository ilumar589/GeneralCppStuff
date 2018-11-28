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