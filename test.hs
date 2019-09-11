f :: Integer -> Integer -> Integer
f x n = if x /= 0 then f (x-1) (n*x) else n