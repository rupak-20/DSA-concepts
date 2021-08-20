# Randomized Quick Sort using Hoare's partition Scheme

# worst case time complexity O(n*n)
# average case time complexity O(nlogn)
# better than quick sort with last element as pivot

import random


def quickSort(array, start, stop):
    if(start < stop):

        pivotindex = randPivot(array, start, stop)

        quickSort(array, start, pivotindex)
        quickSort(array, pivotindex + 1, stop)


# generate random pivot points
def randPivot(array, start, stop):

    # random number between stop/4 and 3*stop/4
    pivot = random.randrange(start, stop)

    array[start], array[pivot] = array[pivot], array[start]
    return partition(array, start, stop)


# make partitions based on the random pivot point
def partition(array, start, stop):
    pivot = start
    i = start - 1
    j = stop + 1
    while True:
        while True:
            i = i + 1
            if array[i] >= array[pivot]:
                break
        while True:
            j = j - 1
            if array[j] <= array[pivot]:
                break
        if i >= j:
            return j
        array[i], array[j] = array[j], array[i]


if __name__ == "__main__":
    arr = [10, 4, 63, 90, 43, 20, 1, 9]
    print(arr)
    quickSort(arr, 0, len(arr) - 1)
    print('array after randomized quick sort ', arr)
