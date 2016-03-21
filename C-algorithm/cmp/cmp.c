/**
	常见的比较函数实现总结 cmp
	
	C++语言，函数对象
	
	C语言，函数指针
	
	常见用于sort()函数
	
	解释：cmp
		Compare function return value Description

		< 0 	elem1 less than elem2
		=0 		elem1 equivalent to elem2
		> 0 	elem1 greater than elem2
*/

enum bool 
{
	false = 0,
	true = 1,
};

bool cmp (int a, int b)
{
	return (bool) (a > b);
}

// sort(arr, arr+len, cmp);



// int型
int cmp(const void* a, const void* b)
{
	return *( (int*)a ) - *( (int*)b );
}

// char型
int cmp(const void* a, const void* b)
{
	return *( (char*)a ) - *( (char*)b );
}

// double型
int cmp(const void* a, const void* b)
{
	return  ( *( (double*)a ) > *( (double*)b ) ) ? 1 : -1;
}

// 结构体一级排序
struct node
{
	int data;
	int index;
};

int cmp(const void* a, const void* b)
{
	return ((node*)a)->data - ((node*)b)->data;
}

// 结构体二级排序
struct node
{
	int x;
	int y;
};

// 第一步按照x排序，若x相等，则按照y排序
int cmp(const void* a, const void* b)
{
	struct node* first = (node*)a;
	struct node* second = (node*)b;
	
	if (first->x != second->x)
	{
		return (first->x - second->x);
	}
	else 
	{
		return (first->y - second->y);
	}
}

// 对字符串排序
int cmp(const void* a, const void* b)
{
	return strcmp( (const char*)a, (const char*)b );
}

// 计算几何中求凸包的cmp
int cmp(const void* a, const void* b)
{
	struct point* first = (point*)a;
	struct point* second = (point*)b;
	
	if ( calc(*first, *second, p[1]) < 0 )	// p[1] ?
	{
		return 1;
	}
	// 如果在一条直线上，则把远的放在前面
	else if ( !calc(*first, *second, p[1]) && 
		dis(first->x, first->y, p[1].x, p[1].y) < dis(d->x, d->y, p[1].x, p[1].y)
		)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}