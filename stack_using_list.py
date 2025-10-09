#!/usr/bin/env python3
"""Stack Implementation using Python List"""
class Stack:
    def __init__(self): self.items=[]
    def push(self,x): self.items.append(x)
    def pop(self): return self.items.pop() if self.items else None
    def peek(self): return self.items[-1] if self.items else None
    def is_empty(self): return not self.items
if __name__=="__main__":
    s=Stack(); s.push(10); s.push(20); print(s.pop())
