/*
 * LotteryFactory.cpp
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */

#include "LotteryFactory.h"

namespace lotto
{

LotteryFactory::LotteryFactory()
{
	// TODO Auto-generated constructor stub
	srand(time(NULL));
}

LotteryFactory::~LotteryFactory() {
	// TODO Auto-generated destructor stub
}

Lottery* LotteryFactory::getLottery(State s)
{
	if (s == LotteryFactory::California)
	{
		Lottery* lotto = new MegaLottery(5, 47, 27);
		return lotto;
	}
	else
	{
		Lottery* lotto = new Lottery(6, 53);
		return lotto;
	}
}

LotteryFactory* LotteryFactory::getInstance()
{
	static LotteryFactory instance;
	return &instance;
}

}
