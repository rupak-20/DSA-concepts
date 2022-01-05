//counting sort

//worst case time complexity is O(n + k) where n is the number of elements in input array and k is the range of input
//auxiliary space required is O(n + k)
//not suitable for datasets with large deviation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countingSort(vector<int> arr)
{
    int maximum = *max_element(arr.begin(), arr.end()), minimum = *min_element(arr.begin(), arr.end());
    int range = maximum - minimum + 1;

    vector<int> counting(range, 0);

    //store the count of minimum number at index 0
    for (auto x : arr)
        counting[x - minimum]++;

    for (int i = 0; i < counting.size() - 1; i++)
        counting[i + 1] += counting[i];

    vector<int> sorted(arr.size(), 0);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        sorted[counting[arr[i] - minimum] - 1] = arr[i];
        counting[arr[i] - minimum]--;
    }

    return sorted;
}

int main()
{
    vector<int> arr = {9, 9, 4, 3, 3, 7, 1, 0, 0, 5};

    cout << "unsorted array: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";

    arr = countingSort(arr);

    cout << "sorted array: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}