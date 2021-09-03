#selection sort

#average and worst time complexity is O(n*n)
#not suitable for large datasets

def selectionSort(arr):
    n = len(arr)
    for i in range(n-1):
        #minimum number is swapped with the number present at index i
        for j in range(i+1, n):
            if arr[j] < arr[i]:
                arr[i], arr[j] = arr[j], arr[i]

arr = [10, 4, 63, 90, 43, 20, 1, 9]
print(arr)
selectionSort(arr)
print('array after selection sort: ', arr)
