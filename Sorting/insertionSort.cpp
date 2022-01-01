// insertion sort

// average and worst time complexity is O(n*n)
// not suitable for large datasets

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int curr = arr[i];
    int j = i - 1;

    // sorted part of array is shifted until the current number is less than the
    // previous one
    while (j >= 0 && arr[j] > curr) {
      arr[j + 1] = arr[j]; // shift right
      j -= 1;
    }
    arr[j + 1] = curr; // place the current number
  }
}

int main() {
  vector<int> array = {10, 4, 63, 90, 43, 20, 1, 9};

  cout << "unsorted array: ";
  for (auto a : array)
    cout << a << " ";
  cout << "\n";

  insertionSort(array);

  cout << "sorted array: ";
  for (auto a : array)
    cout << a << " ";

  return 0;
}