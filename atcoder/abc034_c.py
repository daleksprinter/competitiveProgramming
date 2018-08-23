w,h = map(int,raw_input().split())

import math
mod = 10**9+7
def inv(x):
	return pow(x,mod-2,mod)

def factorial(x):
	retval = 1
	for i in range(2,x+1):
		retval = (retval * i)% mod
	return retval

def nCr(n,r):
	return factorial(n) * inv(factorial(n-r)) * inv(factorial(r)) % mod

print nCr(w+h-2,min(w-1,h-1))
