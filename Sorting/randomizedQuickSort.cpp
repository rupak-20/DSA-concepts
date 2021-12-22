// Randomized Quick Sort using Hoare's partition scheme

// worst case time complexity O(n*n)
// average time complexity O(nlogn)
// better than quick sort with last element as pivot

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

// make partitions based on the random pivots
int partition(vector<int> &arr, int start, int stop) {
  int pivot = start, i = start - 1, j = stop + 1;

  while (true) {
    while (true) {
      i++;
      if (arr[i] >= arr[pivot])
        break;
    }
    while (true) {
      j--;
      if (arr[j] <= arr[pivot])
        break;
    }
    if (i >= j)
      return j;

    // swap elements at index i and j
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

// generating random pivot points
int randPivot(vector<int> &arr, int start, int stop) {

  srand(time(NULL));
  int pivot = (rand() % (stop - start + 1)) + start;

  // swap numbers at index start and pivot
  int temp = arr[start];
  arr[start] = arr[pivot];
  arr[pivot] = temp;

  return partition(arr, start, stop);
}

// quick sort function
void quickSort(vector<int> &arr, int start, int stop) {
  if (start < stop) {
    int pivotindex = randPivot(arr, start, stop);

    quickSort(arr, start, pivotindex);
    quickSort(arr, pivotindex + 1, stop);
  }
}

// driver code
int main() {
  vector<int> array = {10, 4, 63, 90, 43, 20, 1, 9};

  cout << "unsorted array: ";
  for (auto x : array)
    cout << x << " ";
  cout << "\n";
  quickSort(array, 0, array.size() - 1);
  cout << "sorted array: ";
  for (auto x : array)
    cout << x << " ";
  cout << "\n";

  return 0;
}