/**
	红黑树测试程序
	rbtree_check.cpp
*/
#include <iostream>
#include "rbtree.h"
#include <Windows.h>
#include <ctime>

using namespace std;

void time_Test();
void Fun_Test();

int main(){
	cout << "红黑树RBTree测试程序！\n";
	
	Fun_Test();
	
	time_Test();
	
	return 0;
}


void Fun_Test(){
	CRBTree tree;
	tree.RB_InitLeafNode();
	
	tree.RB_Insert(10);
	tree.RB_Insert(14);
	tree.RB_Insert(4);
	tree.RB_Insert(12);
	tree.RB_Insert(11);
	tree.RB_Insert(13);
	tree.RB_Insert(7);
	tree.RB_Insert(16);
	
	tree.RB_Print();
	
	tree.RB_Delete(14);
	tree.RB_Delete(10);
	
	Sleep(1000);
	tree.RB_Print();
}

void time_Test(){
	CRBTree tree;
	clock_t t_insert;
	clock_t t_print;
	clock_t t_find;
	int nArrayNodes[50000];
	
	tree.RB_InitLeafNodes();
	
	srand((unsigned int)time(NULL));
	
	t_insert = clock();
	for (int i = 0; i < 50000; i++){
		nArrayNodes[i] = rand() % 10000000 + 1;
		while (true){
			if (tree.RB_Find(nArrayNodes[i]) == NULL){
				tree.RB_Insert(nArrayNodes[i]);
				break;
			}
			else{
				nArrayNodes[i] = rand() % 10000000 + 1;
			}
		}
	}
	t_insert = clock() - t_insert;
	
	t_print = clock();
	tree.BR_Print();
	t_print = clock() - t_print;
	
	t_find = clock();
	tree.RB_Find(32725);
	t_find = clock() - t_find;
	
	cout << "The tree nodes count is: " << tree.RB_GetSize() << endl;
	cout << "Insert data need time: " << t_insert << "ms." << endl;
	cout << "Print data need time: " << t_print << "ms." << endl;
	cout << "Find one data need time: " << t_find << "ms." << endl;
	
}