#quick sort with last element as pivot

#worst case time complexity O(n*n)
#average case time complexity O(nlogn)

#refer this video if you still have doubts: https://www.youtube.com/watch?v=Dl6HT-NM_q4

def partition(array, start, stop):
    i = (start - 1)
    pivot = array[stop]
    print('pivot point = ', pivot)
    for j in range(start, stop):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i]
            print('swapped integers ', array[i], ' and ', array[j])
    array[i + 1], array[stop] = array[stop], array[i + 1]
    print('swapped integers ', array[i+1], ' and ', array[stop])
    return (i + 1)

def quick_sort(array, start, stop):
    if start < stop:
        partition_index  = partition(array, start, stop)
        print('array in this iteration is: ', array)
        quick_sort(array, start, partition_index  - 1)
        quick_sort(array, partition_index  + 1, stop)

if __name__ == '__main__':
    arr = [10, 4, 63, 90, 43, 20, 1, 9]
    print(arr)
    quick_sort(arr, 0, len(arr)-1)
    print('array after quick sort: ', arr)