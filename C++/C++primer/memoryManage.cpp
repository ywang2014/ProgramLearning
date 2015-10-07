/*
* using the new and delete operator
* memory manage is a complicated skill
*/

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

char* getname(void);

int main()
{
    cout << "Hello girls!" << endl;

    char* name; // create pointer but no storage
/*
    for (int i = 0; i < 5; i++)
    {
        name = getname();
        cout << name << " at " << (int*) name << endl;
        delete []name;  // memory freed. pointer is still existence!
    }
*/
    int ivar = 5;
    int* p = &ivar;
    cout << "p = " << p << endl;
    cout << "&ivar = " << &ivar << endl;
    cout << "&p = " << &p << endl;

    cout << "getname = " << getname << endl;    // 1
    cout << "&getname = " << &getname << endl;  // 1

    cout << "main = " << main << endl;          // 1
    cout << "&main = " << &main << endl;        // 1

    printf("main = %p\n", main);                    // 0x4011a0
    printf("getname = %p\n", getname);              // 0x401432
    printf("&main = %p\n", &main);                  // 0x4011a0
    printf("&getname = %p\n", &getname);            // 0x401432

    printf("%d\n", *(char *)((int)getname));        // 85
    printf("%d\n", *(char *)((int)getname + 1));    // -119

    printf("%p\n", (char *)((int)getname));        // 0x401432      char * == int *
    printf("%p\n", (char *)((int)getname + 1));    // 0x401433

    printf("%p\n", (int *)((int)main));        // 0x4011a0
    printf("%p\n", (int *)((int)main + 1));    // 0x4011a1

    return 0;
}

char* getname(void)
{
    char input[100];    // temporary storage, lost when function ends
    cout << "Enter last name: ";
    cin >> input;

    // strlen(input) + 1    with a null character.
    char* ret = new char[strlen(input) + 1];    // allocate the memory, otherwise anything will be canceled when ending of calling the function

    strcpy(ret, input); // copy the input string into ret

    return ret;
}
