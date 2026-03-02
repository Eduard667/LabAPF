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