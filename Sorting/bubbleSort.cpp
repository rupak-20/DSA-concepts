// bubble sort

// average and worst case time complexity O(n*n)
// not suitable for large datasets

#include <iostream>
#include <vector>
using namespace std;

// bubble sort function
void bubbleSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    bool sorted = false; // to break loop if the array is already sorted

    for (int j = i + 1; j < n; j++) {
      // swap
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        sorted = true;
      }
    }
    if (sorted == false) // if array is already sorted then break
      break;
  }
}

// print array
void print(vector<int> arr) {
  for (auto x : arr)
    cout << x << " ";
  cout << "\n";
}

// driver code
int main() {

  vector<int> a = {10, 4, 63, 90, 43, 20, 1, 9};

  cout << "unsorted array : ";
  print(a);
  bubbleSort(a);
  cout << "sorted array : ";
  print(a);

  return 0;
}