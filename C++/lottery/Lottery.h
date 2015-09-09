/*
 * Lottery.h
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */

#ifndef LOTTERY_H_
#define LOTTERY_H_

// TODO
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>

using namespace std;

namespace lotto
{

class Lottery
{
protected:
	int ticketSize;	// 彩票号码的数目
	int maxNum;		// 最大的彩票号码
	int *generateNumbers();	// 根据彩票上的号码，生成一个数组

public:
	Lottery(int, int);
	virtual ~Lottery();
	virtual string printTicket();	// 创建彩票的一个字符串表示
};

}

#endif /* LOTTERY_H_ */
