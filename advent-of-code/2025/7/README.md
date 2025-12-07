---
title: "Day 7: Laboratories"
url: https://adventofcode.com/2025/day/7
tags: 2d
---

# Solution
Simulate beam splitting. To count the total number of paths, whenever a split is encountered, attach a counter to the beams to accumulate overlapping regions, e.g.:
```
.......1....... # 1 total path
......1^1...... # 2 total paths
......1.1...... # 2 total paths
.....1^2^1..... # 4 total paths
```

# Usage
```
$ make
```
