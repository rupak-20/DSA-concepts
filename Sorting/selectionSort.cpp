// selection sort

// average and worst case time complexity is O(n*n)
// not suitable for large datasets

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &array) {
  int n = array.size();
  for (int i = 0; i < n - 1; i++)
    // minimum number is swapped with the number present at index i
    for (int j = i + 1; j < n; j++) {
      // swap
      if (array[j] < array[i]) {
        array[i] = array[i] + array[j];
        array[j] = array[i] - array[j];
        array[i] = array[i] - array[j];
      }
    }
}

int main() {
  vector<int> arr = {10, 4, 63, 90, 43, 20, 1, 9};
  cout << "unsorted array: ";
  for (auto x : arr)
    cout << x << " ";
  cout << "\n";
  selectionSort(arr);
  cout << "sorted array: ";
  for (auto x : arr)
    cout << x << " ";

  return 0;
}