#insertion sort

#average and worst time complexity is O(n*n)
#not suitable for large datasets

def insertionSort(arr):

    n = len(arr)
    for i in range(1,n):
        current = arr[i]
        j = i-1

        #sorted part of array is shifted until the current number is less than the previous one
        while j >= 0 and arr[j] > current:
            arr[j+1] = arr[j]      #shift right
            j -= 1
        arr[j+1] = current #place the current number

a = [10, 4, 63, 90, 43, 20, 1, 9]

print(a)
insertionSort(a)
print('after insertion sort: ', a)