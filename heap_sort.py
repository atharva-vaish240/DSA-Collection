#!/usr/bin/env python3
"""Heap Sort - O(n log n)"""
def heapify(a,n,i):
    l,r=2*i+1,2*i+2; largest=i
    if l<n and a[l]>a[largest]: largest=l
    if r<n and a[r]>a[largest]: largest=r
    if largest!=i:
        a[i],a[largest]=a[largest],a[i]
        heapify(a,n,largest)
def heap_sort(a):
    n=len(a)
    for i in range(n//2-1,-1,-1): heapify(a,n,i)
    for i in range(n-1,0,-1):
        a[i],a[0]=a[0],a[i]; heapify(a,i,0)
    return a
if __name__=="__main__":
    arr=[4,10,3,5,1]
    print(heap_sort(arr))
