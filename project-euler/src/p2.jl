using Lazy

curry(f, x) = (xs...) -> f(x, xs...)

fibs = @lazy 0:1:(fibs + tail(fibs))

under = curry(takewhile, (x -> x <= 4e6))
even = curry(filter, iseven)
solve = (sum ∘ even ∘ under)

println(solve(fibs))
