class Algorithms:
    def __init__(self):
        pass
    
    # Binary Search algorithm TIME COMPLEXITY: O(log n)
    def b_search(self, array, target):
        l = len(array)
        left = 0
        right = l - 1

        while left <= right:
            mid = (left + right) // 2
            if array[mid] == target:
                return mid
            elif target < array[mid]:
                right = mid - 1
            else:
                left = mid +1
        return -1
    
    
    # Insertion Sort algorithm TIME COMPLEXITY: O(n^2)
    def insertion_sort(self, arr):
        for i in range(1, len(arr)):
            while arr[i - 1] > arr[i] and i > 0:
                arr[i - 1], arr[i] = arr[i], arr[i - 1]
                i -= 1
        return arr


    # Selection Sort algorithm TIME COMPLEXITY: O(n^2)
    def selection_sort(self, arr):
        length = len(arr)
        
        for i in range(0, length - 1):
            min_index = i
            for j in range(i, length):
                if arr[j] < arr[min_index]:
                    min_index = j
            arr[min_index], arr[i] = arr[i], arr[min_index]
        return arr
    
    
    # Bubble Sort algorithm TIME COMPLEXITY: O(n^2)
    def bubble_sort(self, arr):
        n = len(arr)
        for i in range(n):
            for j in range(0, n-i-1):
                if arr[j] > arr[j+1] :
                    arr[j], arr[j+1] = arr[j+1], arr[j]
        return arr


    # Two Sum algorithm O(n)
    def two_sum(self, arr, target):
        seen = {}
        l = len(arr)
        for i in range(l):
            diff = target - arr[i]
            if diff in seen:
                return seen[diff], i
            seen[arr[i]] = i


    # Palindrome algorithm TIME COMPLEXITY: O(n)
    def isPalindrome(self, x:int) -> bool:
        x = str(x)
        if x == x[::-1]:
            return True
        return False


algo = Algorithms()
arr = [3, 2, 1, 5, 6, 4]
print(algo.bubble_sort(arr))