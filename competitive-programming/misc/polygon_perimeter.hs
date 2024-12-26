type Point = (Float, Float)

type Points = [Point]

get :: [Float] -> Points
get [] = []
get (x:y:rest) = (x, y) : get rest

shift :: [a] -> [a]
shift (x:xs) = xs ++ [x]

dist :: Point -> Point -> Float
dist (x1, y1) (x2, y2) = sqrt ((x1 - x2) ** 2 + (y1 - y2) ** 2)

solve :: Points -> Float
solve ps = sum $ zipWith dist ps (shift ps)

main :: IO ()
main = interact $ show . solve . get . map read . concatMap words . tail . lines
