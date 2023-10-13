from sympy import *

n = int(input())

for T in range(n):
    p = int(input())
    res = list(sqrt_mod_iter(1, p))
    res.remove(p - 1)
    print(max(res))


