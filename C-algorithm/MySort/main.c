#include <stdio.h>
#include <stdlib.h>
#include "mysort.h"
#include "mytime.h"

#define SIZE 17

int main()
{
    int i = 0;
    int arr[SIZE] = {1, 2, 4, 5, 7, 8, 0, 3, 6, 9, 14, 47, 78, 85, 52, 20, 36};

    //merge_sort(arr, SIZE);
    //quick_sort(arr, SIZE);
    get_time();
    get_msec();

    heap_sort(arr, SIZE);

    printf("Hello Boy!\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", *(arr+i));
    }

    get_time();
    get_msec();

    return 0;
}
