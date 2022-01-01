// quick sort with last element as pivot

// worst case time complexity O(n*n)
// average case time complexity O(nlogn)

// I refered this video when I was stuck
// https://www.youtube.com/watch?v=Dl6HT-NM_q4

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int stop) {
  int i = start - 1;
  int pivot = arr[stop];
  // cout<<"pivot point = "<<pivot<<"\n";

  for (int j = start; j < stop; j++) {
    if (arr[j] <= pivot) {
      i += 1;
      // swap
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;

      // cout<<"swapped intergers "<<arr[i]<<" and "<<arr[j]<<"\n";
    }
  }
  // swop
  int temp = arr[i + 1];
  arr[i + 1] = arr[stop];
  arr[stop] = temp;
  // cout<<"swapped integers "<<arr[i+1]<<" and "<<arr[stop]<<"\n";

  return (i + 1);
}

void quick_sort(vector<int> &arr, int start, int stop) {
  if (start < stop) {
    int partition_index = partition(arr, start, stop);
    // cout<<"array in this iteration is : ";
    // for(auto x : arr)
    //    cout<<x<<" ";
    // cout<<"\n";
    quick_sort(arr, start, partition_index - 1);
    quick_sort(arr, partition_index + 1, stop);
  }
}

// driver code
int main() {

  vector<int> array = {10, 4, 63, 90, 43, 20, 1, 9};
  cout << "unsorted array : ";
  for (auto x : array)
    cout << x << " ";
  cout << "\n";

  quick_sort(array, 0, array.size() - 1);

  cout << "sorted array : ";
  for (auto x : array)
    cout << x << " ";
  cout << "\n";

  return 0;
}