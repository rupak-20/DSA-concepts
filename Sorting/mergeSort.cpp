// merge sort

// time complexity = O(nlogn)
// space complexity = O(n)

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &arr) {
  if (arr.size() > 1) {

    int mid = arr.size() / 2;
    vector<int> left, right;

    for (int i = 0; i < mid; i++)
      left.push_back(arr[i]);

    for (int j = mid; j < arr.size(); j++)
      right.push_back(arr[j]);

    mergeSort(left);
    mergeSort(right);

    int i = 0, j = 0, k = 0;
    // add the number from divided array to original array
    while (i < left.size() && j < right.size()) {
      if (left[i] < right[j]) {
        arr[k] = left[i];
        i++;
      } else {
        arr[k] = right[j];
        j++;
      }
      k++;
    }

    // add remaining numbers
    while (i < left.size()) {
      arr[k] = left[i];
      i++;
      k++;
    }
    while (j < right.size()) {
      arr[k] = right[j];
      j++;
      k++;
    }
  }
}

int main() {
  vector<int> array = {10, 4, 63, 90, 43, 20, 1, 9};
  cout << "unsorted array: ";
  for (auto x : array)
    cout << x << " ";
  cout << "\n";
  mergeSort(array);
  cout << "sorted array: ";
  for (auto x : array)
    cout << x << " ";

  return 0;
}