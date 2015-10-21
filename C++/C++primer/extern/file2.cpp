/*
 variables width internal and external linkage
 To compiled with file1.cpp
 */
#include <iostream>

extern int tom;     	// tom definal elsewhere. It is impossible to define tom here. ODR
static int dick = 20;	// override external dick with static variable. Valide 
int harry = 200;		// Valide, there is no harry variable in other place with global variable 
extern int var;

void remote_global()
{
	using namespace std;
	cout << "\n-------------------------------------------------------\n";
	cout << "remote_global() reports the following informations: \n";
	cout << "tom = " << tom << "in " << &tom << endl;
	cout << "dick = " << dick << "in " << &dick << endl;
	cout << "harry = " << harry << "in " << &harry << endl;
}

void remote_local()
{
	int var = 2000;
	using namespace std;
	cout << "\n-------------------------------------------------------\n";
	cout << "remote_local() reports the following informations: \n";
	cout << "local dick = " << dick << "in " << &dick << endl;
	cout << "global dick = " << ::dick << "in " << &(::dick) << endl;
	cout << "local var = " << var << "in " << &var << endl;
	cout << "global var = " << ::var << "in " << &(::var) << endl;
}