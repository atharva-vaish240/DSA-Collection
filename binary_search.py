#!/usr/bin/env python3
"""Binary Search - O(log n)"""
def binary_search(arr, target):
    l, r = 0, len(arr)-1
    while l <= r:
        m = (l+r)//2
        if arr[m] == target: return m
        if arr[m] < target: l = m+1
        else: r = m-1
    return -1
if __name__ == "__main__":
    arr=[1,3,5,7,9,11]
    print(binary_search(arr,7))
