// namesp.cpp
// 定义和声明必须位于同一个名称空间

#include <iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;	// 使用cout
	using std::cin;	// 使用cin
	
	void getPerson(Person& rp)
	{
		cout << "Enter first name: ";
		cin >> rp.first_name;
		cout << "Enter last name: ";
		cin >> rp.last_name;
	}
	
	void showPerson(const Person& rp)
	{
		cout << "First name: " << rp.first_name << " Last name: " << rp.last_name;
	}
}

namespace debts
{
	void getDebt(Debt& rd)
	{
		getPerson(rd.name);
		std::cout << "Enter debt: ";
		std::cin >> rd.amount;
	}
	
	void showDebt(const Debt& rd)
	{
		showPerson(rd.name);
		std::cout << ": $" << rd.amount << std::endl;
	}
	
	double sumDebts(const Debt arr[], int n)
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += arr[i].amount;
		}
		return sum;
	}
}