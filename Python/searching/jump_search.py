import math

def jump_search(arr, target):
    n = len(arr)
    step = int(math.sqrt(n))  # Optimal block size
    prev = 0

    # Jump ahead in blocks
    while arr[min(step, n)-1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

    # Linear search in the block
    for i in range(prev, min(step, n)):
        if arr[i] == target:
            return i
    return -1
