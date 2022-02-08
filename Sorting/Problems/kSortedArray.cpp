//given an array of n elements, where each element is atmost k units aways from its position in the sorted array
//devise an algorithm that sorts the array.
//for example, {6, 5, 3, 2, 8, 10, 9} is a k-sorted array with k = 3
//expected output : {2, 3, 5, 6, 8, 9, 10}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//function decleration
vector<int> ksorted_insertionSort(vector<int>); //sorts in O(nk)
vector<int> ksorted_heapSort(vector<int>, int); //sorts in O(k) + O((n-k)*log(k)), takes O(k) auxillary space

//driver code
int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    cout << "given array: ";
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";

    vector<int> res = ksorted_insertionSort(arr);
    cout << "sorted array using insertion sort: ";
    for (auto x : res)
        cout << x << " ";
    cout << "\n";

    res.clear();
    res = ksorted_heapSort(arr, k);
    cout << "sorted array using heap sort: ";
    for (auto x : res)
        cout << x << " ";

    return 0;
}

//sorting array using insertion sort
vector<int> ksorted_insertionSort(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i - 1, save = arr[i];

        for (; j >= 0 && arr[j] > save; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = save;
    }

    return arr;
}

//sorting array using heap sort
vector<int> ksorted_heapSort(vector<int> arr, int k)
{
    int size = (arr.size() == k) ? k : k + 1;
    //insert first k+1 elements in min heap
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int index = 0;

    //remove min element from heap and add to the array and add remaining elements from array to the heap
    for (int i = k + 1; i < arr.size(); i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    //copy the remaining elements to the array
    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }

    return arr;
}