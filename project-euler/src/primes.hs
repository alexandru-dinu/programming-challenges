build :: (a -> a) -> a -> [a]
build next init = init : build next (next init)

naturals = build (+ 1) 0

sieve (h:t) = h : sieve (filter (\x -> mod x h /= 0) t)

primes = sieve $ drop 2 naturals

res n = last $ take n primes
