#merge sort

#time complexity = O(nlogn)
#space complexity = O(n)

def mergeSort(arr):
    if len(arr) > 1:

        mid = len(arr)//2
        l1 = arr[:mid]
        l2 = arr[mid:]

        mergeSort(l1)
        mergeSort(l2)

        i = j = k = 0
        # add the number from divided array to original array
        while i < len(l1) and j < len(l2):
            if l1[i] < l2[j]:
                arr[k] = l1[i]
                i += 1
            else:
                arr[k] = l2[j]
                j += 1
            k += 1
        
        #add remaining numbers from l1 to the array
        while i < len(l1):
            arr[k] = l1[i]
            i += 1
            k += 1
        
        #add reamining numbers from l2 to the array
        while j < len(l2):
            arr[k] = l2[j]
            j += 1
            k += 1

if __name__ == '__main__':
    arr = [10, 4, 63, 90, 43, 20, 1, 9]
    print(arr)
    mergeSort(arr)
    print('array after merge sort: ', arr)