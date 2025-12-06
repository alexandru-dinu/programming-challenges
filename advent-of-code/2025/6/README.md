---
title: "Day 6: Trash Compactor"
url: https://adventofcode.com/2025/day/6
tags: parsing
---

# Solution
For part 1, simply store all nums in an array (for easier indexing) and perform the operation.

For part 2, read from top to bottom and construct the numbers accordingly. The numbers for the current operation are accumulated until we read only whitespace (meaning we have to switch to a new operation).

# Usage
```
$ make
```
