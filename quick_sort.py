#!/usr/bin/env python3
"""Quick Sort - O(n log n) avg"""
def quick_sort(a):
    if len(a)<=1: return a
    pivot=a[len(a)//2]
    left=[x for x in a if x<pivot]
    mid=[x for x in a if x==pivot]
    right=[x for x in a if x>pivot]
    return quick_sort(left)+mid+quick_sort(right)
if __name__=="__main__":
    arr=[9,3,1,5,13,12]
    print(quick_sort(arr))
