// using the draft of the Time class to test
// complie usetime.cpp and mytime.cpp together

#include <iostream>
#include <fstream>
#include "mytime.h"

int main()
{
	using namespace std;
	
	Time program(3, 45);
	Time reading(2, 30);
	Time temp;
	
	ofstream fout;
	fout.open("result.txt");
	
	cout << "Program and reading \n";
	fout << "Program and reading \n";
	
	cout << "Program time: " << program << endl;
	fout << "Program time: " << program << endl;
	cout << "Reading time: " << reading << endl;
	fout << "Reading time: " << reading << endl;
	
	temp = program + reading;
	cout << "Program + reading = " << temp << endl;
	fout << "Program + reading = " << temp << endl;
	
	temp = 2 * temp;
	cout << "2 * temp = " << temp << endl;
	fout << "2 * temp = " << temp << endl;
	
	cout << "****************** Test ending *******************\n";
	fout << "****************** Test ending *******************\n";
	
	return 0;
}