#counting sort

#worst time complexity is O(n + k) where n is number of elements in input array and k is the range of input
#auxiliary space required is O(n + k)
#not suitable for datasets with large deviation

def countingSort(arr):
    maximum = max(arr)
    minimum = min(arr)
    rangeofelements = maximum - minimum + 1
    counting = [0 for i in range(rangeofelements)]

    #store the count of minimum number at index 0
    for i in arr:
        counting[i - minimum] += 1

    for i in range(len(counting) - 1):
        counting[i+1] += counting[i]
    
    sorted = [0 for i in arr]
    for i in arr[::-1]:
        sorted[counting[i - minimum] - 1] = i
        counting[i - minimum] -= 1

    return sorted

if __name__ == '__main__':

    arr = [9, 9, 4, 3, 3, 7, 1, 0, 0, 5]
    print(arr)
    arr = countingSort(arr)
    print('array after counting sort: ', arr)
