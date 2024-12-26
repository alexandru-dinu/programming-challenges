gen x n
  | x < n =
    if mod x 3 == 0 || mod x 5 == 0
      then x : rest
      else rest
  | otherwise = []
  where
    rest = gen (x + 1) n

res lim = sum $ gen 3 lim
