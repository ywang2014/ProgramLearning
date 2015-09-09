/*
 * MegaLottery.cpp
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */

#include "MegaLottery.h"

using namespace std;

namespace lotto {

MegaLottery::MegaLottery(int ticketSize, int maxNum, int maxMegaNum):
	Lottery(ticketSize, maxNum)
{
	// TODO Auto-generated constructor stub
	this->maxMegaNum = maxMegaNum;
}

MegaLottery::~MegaLottery() {
	// TODO Auto-generated destructor stub
}

string MegaLottery::printTicket()
{
	ostringstream tick;
	tick << Lottery::printTicket() << " Mega: ";
	int mega = 1 + rand() % this->maxMegaNum;
	tick << mega;
	return tick.str();
}
}
