//radix sort

//worst case time complexity O((n+b) * log(k)/log(b)) where n is the size of the array,
//b is the base for representing numbers and k is the range of the numbers

// Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort?
//NO

//If we have log(n)/log(2) bits for every digit, the running time of Radix appears to be better than
//Quick Sort for a wide range of input numbers. The constant factors hidden in asymptotic notation are
//higher for Radix Sort and Quick-Sort uses hardware caches more effectively. Also, Radix sort uses
//counting sort as a subroutine and counting sort takes extra space to sort numbers.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//countinng sort subroutine
void countingSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> res(n);     //output array
    vector<int> count(10); //taking maximum number of digits in the input array as 10 for simplicity

    //counting occurences
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    //changing count so that count contains the position of this digit
    for (int i = 0; i < 10 - 1; i++)
    {
        count[i + 1] += count[i];
    }

    //building the output array
    for (int i = n - 1; i >= 0; i--)
    {
        res[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    //copying the resultant array to arr
    for(int i=0; i<n; i++) {
        arr[i] = res[i];
    }
}

void radixSort(vector<int> &arr)
{
    int maxNum = *max_element(arr.begin(), arr.end());

    for (int i = 1; maxNum / i > 0; i *= 10)
    {
        countingSort(arr, i);
    }
}

//driver function
int main()
{
    vector<int> arr = {9, 9, 4, 3, 3, 7, 1, 0, 0, 5};

    cout << "unsorted array: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";

    radixSort(arr);

    cout << "sorted array: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}