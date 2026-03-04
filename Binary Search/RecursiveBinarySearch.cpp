#include "RecursiveBinarySearch.h"
#include <stdio.h>
#include <stdbool.h> // For bool, true, false
#include <stdlib.h>  // For exit()


bool RecursiveBinarySearch::binarySearch(int* list, int size, int value)
{
    if (size <= 0) return false;

    int mid = size / 2;

    if (list[mid] == value) return true;
    else if (value > list[mid])
        return binarySearch(list + mid + 1, size - mid - 1, value);
    else
        return binarySearch(list, mid, value);
}


