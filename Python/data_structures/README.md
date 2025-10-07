# Segment Tree (Python)

This folder contains a Segment Tree implementation used for range queries (sum) and point updates.

Files:
- `segment_tree.py` — SegmentTree implementation (range sum, point update)

Usage:
```python
from segment_tree import SegmentTree

arr = [1, 3, 5, 7, 9, 11]
st = SegmentTree(arr)
print(st.range_sum(1, 3))
st.update(1, 10)
print(st.range_sum(1, 3))
```
