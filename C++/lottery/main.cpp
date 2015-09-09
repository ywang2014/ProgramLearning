/*
 * main.cpp
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */
#include <iostream>
#include "LotteryFactory.h"

using namespace std;
using namespace lotto;

int main()
{
	LotteryFactory* factory = LotteryFactory::getInstance();
	cout << "What lottery do you want to play?" << endl;
	cout << "(1)California, (2)Florida" << endl;
	int cmd;
	cin >> cmd;
	Lottery* lotto = 0;
	switch (cmd)
	{
	case 1 :
		lotto = factory->getLottery(LotteryFactory::California);
		break;
	case 2 :
		lotto = factory->getLottery(LotteryFactory::Florida);
				break;
	default:
		cout << "Sorry didn't understand that" << endl;
	}
	cout << "Ticket: " << lotto->printTicket() << endl;
	delete lotto;
	return 0;
}
