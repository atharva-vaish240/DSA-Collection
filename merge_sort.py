#!/usr/bin/env python3
"""Merge Sort - Stable, O(n log n)"""
def merge_sort(a):
    if len(a)<=1: return a
    mid=len(a)//2
    L=merge_sort(a[:mid]); R=merge_sort(a[mid:])
    res=[]; i=j=0
    while i<len(L) and j<len(R):
        if L[i]<=R[j]: res.append(L[i]); i+=1
        else: res.append(R[j]); j+=1
    return res+L[i:]+R[j:]
if __name__=="__main__":
    print(merge_sort([5,3,8,6,2,7,4,1]))
