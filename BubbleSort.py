#Bubble sort

#average and worst case time complexity O(n*n)
#not suitable for large datasets

def bubbleSort(arr):
    n = len(arr)

    for i in range(n):
        sorted = False

        for j in range(i+1,n):
            if arr[i] > arr[j]:
                arr[i], arr[j]  = arr[j], arr[i]
                sorted = True
        
        if sorted == False:     #if array is already sorted then break
            break

a = [10, 4, 63, 90, 43, 20, 1, 9]

print(a)
bubbleSort(a)
print('sorted array: ', a)