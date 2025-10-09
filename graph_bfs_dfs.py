#!/usr/bin/env python3
"""Singly Linked List Implementation"""
class Node:
    def __init__(self,data): self.data=data; self.next=None
class LinkedList:
    def __init__(self): self.head=None
    def append(self,data):
        n=Node(data)
        if not self.head: self.head=n; return
        cur=self.head
        while cur.next: cur=cur.next
        cur.next=n
    def display(self):
        cur=self.head
        while cur: print(cur.data,end=" -> "); cur=cur.next
        print("None")
if __name__=="__main__":
    l=LinkedList(); [l.append(i) for i in [1,2,3,4]]; l.display()
