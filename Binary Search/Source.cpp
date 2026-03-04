#include <iostream>
#include <fstream>
#include "RecursiveBinarySearch.h"
#include "IterativeBinarySearch.h"
using namespace std;

int main(int, char**)
{
    const int MAX_SIZE = 100;
    int list[MAX_SIZE];
    int size = 0;

    ifstream input("binarysearchIn.txt");

    if (!input)
    {
        cout << "error opening file" << endl;
        return 1;
    }

    // Read numbers from file
    while (input >> list[size])
    {
        size++;
        if (size >= MAX_SIZE)
        {
            break;
        }
    }
    input.close();

    cout << "Read " << size << " numbers from file." << endl;

    // Ask user for a value to search
    int value;
    cout << "Enter a value to search for: ";
    cin >> value;

    // Perform Recursive binary search
    RecursiveBinarySearch rbs;
    bool found = rbs.binarySearch(list, size, value);

    // Output result
    if (found)
    {
        cout << value << " was found in the list." << endl;
    }
    else
    {
        cout << value << " was NOT found in the list." << endl;
    }

    cout << "Enter a value to search for: ";
    cin >> value;

    // Perform Iterative binary search
    IterativeBinarySearch ibs;
    found = ibs.binarySearch(list, size, value);

    // Output result
    if (found)
    {
        cout << value << " was found in the list." << endl;
    }
    else
    {
        cout << value << " was NOT found in the list." << endl;
    }

    return 0;
}
