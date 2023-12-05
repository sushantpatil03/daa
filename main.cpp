def binary_search(arr, low, high, x):
    if high >= low:
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else: return binary_search(arr, mid + 1, high, x)
    else: return -1

def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)


# Function to perform binary search on a sorted list
def binary_search_on_sorted_list(arr, x):
    low, high = 0, len(arr) - 1
    result = binary_search(arr, low, high, x)
    return result


import random
unsorted_list = [random.randint(1, 10000) for _ in range(5000)]
sorted_list = quicksort(unsorted_list)
element_to_search = int(input("Enter the element to search: "))
index = binary_search_on_sorted_list(sorted_list, element_to_search)


if index != -1:
    print(f"Element {element_to_search} found at index {index}.")
else:
    print(f"Element {element_to_search} not found in the list.")
