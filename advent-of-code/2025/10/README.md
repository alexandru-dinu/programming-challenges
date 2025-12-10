---
title: "Day 10: Factory"
url: https://adventofcode.com/2025/day/10
tags: sat
---

# Solution
Form a button matrix `A` after binary-encoding the buttons and representing as columns. Similar for the goal `G`. `J` is the joltage array. Then we form the following systems of equations:
```
(A * X) % 2 = G (part 1)
(A * X)     = J (part 2)
```
which can both be solved using Z3.

# Usage
```
$ make
```
