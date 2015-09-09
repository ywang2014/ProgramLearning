/*
 * print.cpp
 *
 *  Created on: 2015-9-8
 *      Author: ZKY
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL)
	{

	}
};


class Solution {
public:
	// 递归解决
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> element;
        if (head != NULL)
            {
            if (head->next != NULL)
                {
                element = printListFromTailToHead(head->next);
            }
            element.push_back(head->val);
        }
        return element;
    }
    /*
     // insert(post, val)
      * 直接循环
      * vector<int> elem;
      * while (head != NULL)
      * {
      * 	elem.insert(0, head->val);
      * 	head = head->next;
      * }
     */
};

int main()
{
	Solution s;
	struct ListNode list[] = {60, 0, 1, 34};	// 初始化一个链表？？？
	vector<int> res = s.printListFromTailToHead(list);
	cout << res[0] << endl;
	return 0;
}
