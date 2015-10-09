/*
* Text file input and output
* Some based skill about read a text file and write a text file!
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main()
{
    using namespace std;

    ifstream input;     // object for handling file input
    ofstream output;    // object for handling file output

    output.open("test.txt");    // associate output with a file, It will create a file when the file does not exist.

    cout << "Test is coming..." << endl;
    output << "Test is coming..." << endl;

    cout << "Product 100 random numbers: " << endl;
    output << "Product 100 random numbers: " << endl;

    int randomNum = 0;
    srand(unsigned(time(0)));
    for (int i = 0; i < 100; i++)
    {
        randomNum = rand() % (100 - i) + i;
        cout << randomNum << " ";
        output << randomNum << " ";
    }

    cout << endl << "Random numbers have producted!" << endl;
    output << endl;
    output.close();

    cout << endl << "*********************************************" << endl << endl;
    cout << "Enter name of data file: ";
    char filename[20];
    cin.getline(filename, 20);
    cout << "Reading is comming..." << endl;
    input.open(filename);   // associate input with a file.
    output.open("log.txt");

    if (! input.is_open())  // failed to open file
    {
        cout << "Could not open the file " << filename << endl;

        output << "Failed log: " << endl;
        output << "Last time, reading the file " << filename << " is failed. " << endl;
        output << "Time: " << time(0) << endl;
        output.close();
        exit(EXIT_FAILURE);
    }

    output << "Succeed log: " << endl;
    cout << "Show the whole file: " << endl << endl;
    output << "Show the whole file: " << endl;
    output << "Time: " << time(0) << endl;

    int ch_count = 0;
    int int_count = 0;
    char ch;
    int value;

    for (int i = 0; i < 2; i++)
    {
        ch = input.get();
        while (ch != '\n')
        {
            ch_count++;
            cout << ch;
            input.get(ch);
        }
        ch_count++;
        cout << endl;
    }

    while (input >> value) // while input well and not at EOF
    {
        int_count++;
        cout << value << " ";
    }

    if (input.eof())
    {
        cout << "End of file reached.\n";
        output << "End of file reached.\n";
    }
    else if (input.fail())
    {
        cout << "Input terminated by data mismatch.\n";
        output << "Input terminated by data mismatch.\n";
    }
    else
    {
        cout << "Input terminated for unknown reason.\n";
        output << "Input terminated for unknown reason.\n";
    }

    input.close();  // finished with the file

    if (ch_count == 0)
    {
        cout << "No characters processed.\n";
        output << "No characters processed.\n";
    }
    else
    {
        cout << "The file " << filename << " has " << ch_count << " characters.\n";
        output << "The file " << filename << " has " << ch_count << " characters.\n";
    }

    if (int_count == 0)
    {
        cout << "No numbers processed.\n";
        output << "No numbers processed.\n";
    }
    else
    {
        cout << "The file " << filename << " has " << int_count << " random numbers.\n";
        output << "The file " << filename << " has " << int_count << " random numbers.\n";
    }

    output.close();

    return 0;
}
