# Lab F
# 1. Code refactored header file for Grid.h
```cpp
#pragma once
#include <iostream>
#include <fstream>

template <class T>
class Grid
{
public:
    Grid();
    ~Grid();

    void LoadGrid(const char filename[]);
    void SaveGrid(const char filename[]);

private:
    T m_grid[9][9];
};


// Method Implementations


template <class T>
Grid<T>::Grid() {}

template <class T>
Grid<T>::~Grid() {}

template <class T>
void Grid<T>::LoadGrid(const char filename[])
{
    std::ifstream fin(filename);
    for (int x = 0; x < 9; x++)
        for (int y = 0; y < 9; y++)
            fin >> m_grid[x][y];
}

template <class T>
void Grid<T>::SaveGrid(const char filename[])
{
    std::ofstream fout(filename);
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
            fout << m_grid[x][y] << " ";
        fout << "\n";
    }
}

// operator<<
template <class T>
std::ostream& operator<<(std::ostream& os, const Grid<T>& g)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
            os << g.m_grid[x][y] << " ";
        os << "\n";
    }
    return os;
}

// operator>>
template <class T>
std::istream& operator>>(std::istream& is, Grid<T>& g)
{
    for (int x = 0; x < 9; x++)
        for (int y = 0; y < 9; y++)
            is >> g.m_grid[x][y];

    return is;
}
```

# Template Grid
Here we have a display of our grid, in the local variables window, which shows our grid values are floating point value, and output of our OutGrid.txt file.
<img width="934" height="334" alt="image" src="https://github.com/user-attachments/assets/a8a10938-3a65-46f5-9c6b-547385198a59" />
<img width="241" height="264" alt="image" src="https://github.com/user-attachments/assets/19915b4e-c160-451b-ae50-a9fcda6ef396" />

Here we have a display of the float values in memory stack, as they take up a word, 4 bytes (32bits), we can split the memory for visual ease like this: 
00 00 80 3f   00 00 00 40   00 00 40 40   00 00 80 40  00
but we can determine that each sequence, or each 4 bytes is a floating point value.
for example: 
00 00 80 3F = 1.0f (IEEE - 754 encoding)
<img width="414" height="72" alt="image" src="https://github.com/user-attachments/assets/e614633b-0ca9-4cef-971b-50754c7afb2a" />

## Code for Main 
### Explanation:
The line ```cpp Grid<float> grid;``` has been changed from an int type, to enable us to use floating point value instead as required in the lab book. 
```cpp
#include <iostream>
#include "Grid.h"
#include <string>
#include <fstream>
using namespace std;

int main(int argn, char* argv[])
{
    Grid<float> grid;
    grid.LoadGrid("Grid1.txt");
    grid.SaveGrid("OutGrid.txt");

    // Print the contents of OutGrid.txt to the console
    std::ifstream fin("OutGrid.txt");
    std::cout << "Contents of OutGrid.txt:\n\n";
    std::string line;
    while (getline(fin, line)) {
        std::cout << line << "\n";
    }


	//Grid grid;
	//grid.LoadGrid("Grid1.txt");
	//grid.SaveGrid("OutGrid.txt");

}
```
# Binary Search
Iteration: Repeating work using **explicit looping constructs** - for, while, do...while
e.g. 
```cpp
int sum = 0;
for (int i = 1; i <= 5; i++)
    sum += i;
```
Recursion: function calls itself to repeat work - creating a new stack frame each time.
```cpp
int sum(int n)
{
    if (n == 0) return 0;
    return n + sum(n - 1);
}
```
## 1. Binary search with Iteration

## 2. Binary search with Recursion
