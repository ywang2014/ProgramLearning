#include <iostream>
#include <cstdlib>
#include "lunarholiday.h"
#include "day.h"

using namespace std;

static Day day[31];

int main()
{
    int year;
    int month;
    for (int i = 0; i < 31; i++)
    {
        day[i].s_day = i + 1;
    }

    while (true)
    {
        cout << "Hello boys!" << endl;
        cout << "Please input year: ";
        cin >> year;
        cout << "Please input year: ";
        cin >> month;

        system("cls");

        cout << "\n*********************** " << year << "-" << month << " ************************\n\n";

        cout << "星期一\t 星期二\t星期三\t星期四\t星期五\t星期六\t星期日\n";
        for (int i = 0; i < 31; i++)
        {
            if (i % 7 == 0 && i != 0)
            {
                cout << endl;
            }
            cout << "  " << day[i].s_day << "\t";
        }
        cout << endl;

        char flag = '\0';
        while (true)
        {
            cout << "Quit: q, Continue: c";
            cin >> flag;
            if (flag == 'q' || flag == 'Q' || flag == 'c' || flag == 'C')
            {
                break;
            }
            else
            {
                cout << "Invalid input, please input again!" << endl;
            }
        }
        if (flag == 'q' || flag == 'Q')
        {
            break;
        }
    }
    return 0;
}
