/*
 * Lottery.cpp
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */

#include "Lottery.h"

namespace lotto
{

Lottery::Lottery(int size, int num)
{
	// TODO Auto-generated constructor stub
	this->ticketSize = size;
	this->maxNum = num;

}

Lottery::~Lottery()
{
	// TODO Auto-generated destructor stub
}

int* Lottery::generateNumbers()
{
	// allNums数组用于跟踪到目前为止已经生成的数字，确保不会在彩票上获得重复的数字
	int* allNums = new int[this->maxNum + 1];
	for (int i = 0; i <= this->maxNum; i++)
	{
		allNums[i] = 0;
	}
	int* nums = new int[this->ticketSize];
	for (int i = 0; i < this->ticketSize; i++)
	{
		int val = 1 + rand() % (this->maxNum);
		if (allNums[val])
		{
			i--;
		}
		else
		{
			nums[i] = val;
			allNums[val] = 1;
		}
	}
	return nums;
}

string Lottery::printTicket()
{
	ostringstream str;
	int* nums = this->generateNumbers();
	for (int i = 0; i < this->ticketSize; i++)
	{
		str << *nums << ' ';
		nums++;
	}
	return str.str();
}
}
