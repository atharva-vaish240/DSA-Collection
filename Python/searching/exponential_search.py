def exponential_search(arr, target):
    if arr[0] == target:
        return 0

    i = 1
    while i < len(arr) and arr[i] <= target:
        i *= 2

    return binary_search(arr[:min(i, len(arr))], target)

# Example
arr = [11, 15, 23, 45, 70, 91, 101, 120]
print("Exponential Search:", exponential_search(arr, 70))  # Output: 4
