solve :: [Int] -> [Int] -> Int
solve xs ys = length $ filter (\x -> mod g x == 0) m
  where
    g = gcd' ys
    m = map (* (lcm' xs)) [1 .. g]

lcm' :: [Int] -> Int
lcm' = foldl1 lcm

gcd' :: [Int] -> Int
gcd' = foldl1 gcd

getIntList :: IO [Int]
getIntList = map read . words <$> getLine

main :: IO ()
main = do
  [n, m] <- getIntList
  xs <- getIntList
  ys <- getIntList
  print $ solve xs ys
