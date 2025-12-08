---
title: "Day 8: Playground"
url: https://adventofcode.com/2025/day/8
tags: sets
---

# Solution
Initially implemented a naive union-find and a sub-optimal mergeable node selection.

Instead of filtering the set of mergeable nodes, we can sort the pairs of nodes by distance and merge iteratively.

Path compression:
```
union(0, 1)
union(1, 2)
union(2, 3)
parents = {0: 1, 1: 2, 2: 3, 3: 3}
    0 -> 1 -> 2 -> 3<

find(0) will resolve the parents so all point to 3:
parents = {0: 3, 1: 3, 2: 3, 3: 3}
```

# Usage
```
$ make
```
