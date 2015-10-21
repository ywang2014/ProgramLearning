// namespace application
#include <string>

// create the persons and debts namespaces
namespace pers 
{
	struct Person
	{
		std::string first_name;
		std::string last_name;
	};
	
	void getPerson(Person&);
	void showPerson(const Person&);
}

namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount;
	};
	
	void getDebt(Debt&);
	void showDebt(const Debt&);
	double sumDebts(const Debt arr[], int n);
}