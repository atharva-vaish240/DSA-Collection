import math

def jump_search(arr, x):
    n = len(arr)
    step = int(n ** 0.5)  # <-- indentation fixed
    prev = 0

    # Jump ahead in blocks
    while arr[min(step, n)-1] < target:
        step = int(math.sqrt(n))
        prev = 0

    while arr[min(step, n) - 1] < target:
main
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

 main
    # Linear search in the block

 main
    for i in range(prev, min(step, n)):
        if arr[i] == target:
            return i
    return -1
main

# Example (sorted array required)
arr = [11, 15, 23, 45, 70]
print("Jump Search:", jump_search(arr, 45))  # Output: 3
 main
