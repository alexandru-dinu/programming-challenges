---
title: "Day 9: Movie Theater"
url: https://adventofcode.com/2025/day/9
tags: geometry, 2d
---

# Solution

Considered convex hull, but realised it won't work due to the pathological shape of the polygon.

Used hints from subreddit and learned about [shapely](https://shapely.readthedocs.io/en/stable), which worked, but didn't feel right.

Then I realised the input is given nicely in CW traversal, so we already have the polygon shell.
Then, following [this hint][1], the (brute-force) idea, based on the observation above and axis-aligned coordinates, is to consider only rectangles which don't intersect with any shell segments, meaning that all shell segments must be outside the rectangle (all to the left, to the right, top, or bottom).

[1]: https://www.reddit.com/r/adventofcode/comments/1phywvn/comment/nt2hps9/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button

# Usage
```
$ make
```
