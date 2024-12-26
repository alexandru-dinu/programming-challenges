solve :: [Int] -> String
solve [x1, v1, x2, v2]
  | (v2 < v1) && (x2 - x1) `mod` (v1 - v2) == 0 = "YES"
  | otherwise = "NO"

main :: IO ()
main = interact $ solve . map read . words
