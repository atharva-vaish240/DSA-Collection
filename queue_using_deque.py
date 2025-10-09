#!/usr/bin/env python3
"""Queue Implementation using collections.deque"""
from collections import deque
class Queue:
    def __init__(self): self.q=deque()
    def enqueue(self,x): self.q.append(x)
    def dequeue(self): return self.q.popleft() if self.q else None
    def is_empty(self): return not self.q
if __name__=="__main__":
    q=Queue(); q.enqueue(1); q.enqueue(2); print(q.dequeue())
