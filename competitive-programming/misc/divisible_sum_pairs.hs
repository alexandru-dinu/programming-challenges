enumerate :: [a] -> [(Int, a)]
enumerate xs = zip [1 .. length xs] xs

solve :: [Int] -> Int
solve (k:xs) = length good
  where
    ixs = enumerate xs
    good = [1 | (i, x) <- ixs, (j, y) <- ixs, i < j, (x + y) `mod` k == 0]

main :: IO ()
main = interact $ show . solve . map read . tail . words
