--	tail-recursive fibonacci
f _ v 1 = v
f a b n = f b (a + b) (n - 1)

trfib = f 0 1

--	infinite-list fibonacci
inffib = zipWith (+) (0 : 1 : inffib) (1 : inffib)

res up =
  sum $
  filter even $
  foldr
    (\e l ->
       if e < up
         then e : l
         else [])
    []
    inffib
