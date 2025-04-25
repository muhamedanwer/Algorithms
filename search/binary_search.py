def binary_search(arr : list, n : int) -> int:
    """
    Performs binary search on a sorted list to find the index of the number 'n'.
    Args:
        arr (list): A sorted list of numbers.
        n (int): The number to search for.
    Returns:
        int: The index of 'n' if found, else -1.
    """
    
    if not arr:
        return -1 
    
    left = 0
    right = len(arr) - 1

    while (left <= right):
        middle = left + (right - left) // 2

        if (n == arr[middle]):
            return middle
        elif (n < arr[middle]):
            right = middle - 1
        else:
            left = middle + 1
    return -1   


