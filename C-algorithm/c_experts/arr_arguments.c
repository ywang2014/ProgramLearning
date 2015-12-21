#include <stdio.h>
#include <stdlib.h>

char ga[] = "abcdefg";

void arr_func(char ca[])
{
    printf("address of array param = %#x \n", &ca);
    printf("address of (ca[0]) = %#x \n", &(ca[0]));
    printf("address of (ca[1]) = %#x \n", &(ca[1]));
    printf("++ca = %#x \n\n", ++ca);
}

void ptr_func(char *pa)
{
    printf("address of ptr param = %#x \n", &pa);
    printf("address of (pa[0]) = %#x \n", &(pa[0]));
    printf("address of (pa[1]) = %#x \n", &(pa[1]));
    printf("++pa = %#x \n\n", ++pa);
}

int main(void)
{
    char *p = ga;

    printf("address of global = %#x \n", &ga);
    printf("address of (ga[0]) = %#x \n", &(ga[0]));
    printf("address of (ga[1]) = %#x \n\n", &(ga[1]));

    printf("address of p = %#x \n\n", p);
    printf("address of &p = %#x \n\n", &p);

    arr_func(ga);
    ptr_func(ga);

    arr_func(p);
    ptr_func(p);

    return 0;
}