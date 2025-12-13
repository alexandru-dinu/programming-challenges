---
title: "Day 11: Reactor"
url: https://adventofcode.com/2025/day/11
tags: graphs, memo
starred: true
---

# Solution
Tried BFS + pruning by level, but it underestimates the solution by pruning too many paths.

Since we count paths, we may encounter the same nodes multiple times
```
.     .
.     .
v     v
A     B
 \   /
  \ /
   v
   C
   .
   .
   v
  out
```
Assume we reach `out` via `* -> A -> C -> * -> out`. We'll "solve" node C and cache its result. Next, we'll encounter C again via the path from B and we'll have to solve C again, but instead we'll use the cached value.

The "result" of a node is the number of paths from that node to `out` via the nodes of interest `dac` and `fft`. Therefore, the search state (to be cached) is `(current node, seen "dac", seen "fft")`.

# Usage
```
$ make
```
