/*
 * MegaLottery.h
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */

#ifndef MEGALOTTERY_H_
#define MEGALOTTERY_H_

#include "Lottery.h"
using std::string;

namespace lotto
{

class MegaLottery : public lotto::Lottery
{
protected:
	int maxMegaNum;	// mega号码可以获得的最大值
public:
	MegaLottery(int, int, int);
	virtual ~MegaLottery();
	string printTicket();
};

}

#endif /* MEGALOTTERY_H_ */
