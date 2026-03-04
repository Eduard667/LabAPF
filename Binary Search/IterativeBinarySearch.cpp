#include "IterativeBinarySearch.h"



// Iterative binary search function
bool IterativeBinarySearch::binarySearch(int* list, int size, int value)
{
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2; // Prevents overflow

		if (list[mid] == value) {
			return true; // Found
		}
		else if (value > list[mid]) {
			left = mid + 1; // Search right half
		}
		else {
			right = mid - 1; // Search left half
		}
	}

	return false; // Not found
}
