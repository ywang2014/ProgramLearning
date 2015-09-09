/*
 * LotteryFactory.h
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */

#ifndef LOTTERYFACTORY_H_
#define LOTTERYFACTORY_H_
#include "MegaLottery.h"
#include "Lottery.h"

namespace lotto
{

class LotteryFactory
{
public:
	enum State {California, Florida};
	static LotteryFactory* getInstance();
	Lottery* getLottery(State);
	virtual ~LotteryFactory();
private:
	LotteryFactory();
};

}

#endif /* LOTTERYFACTORY_H_ */
