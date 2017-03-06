#ifndef MERGE_SORT_H
#define MERFE_SORT_H

struct Point{
	int x;
	int y;
};

struct Rectangle{
	Point l_t;	// left top
	Point r_b;	// right bottom
};

void merge(Rectangle *arr, int low, int mid, int high);

void mergeSort(Rectangle *arr, int n);

#endif


