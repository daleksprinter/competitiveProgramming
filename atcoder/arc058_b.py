import math
mod = 10**9+7
def inv(x):
	return pow(x,mod-2,mod)


MAX = 10**5*3
facts = [1 for i in range(MAX)]
invs = [1 for i in range(MAX)]


def factorial(x):
	for i in range(1,x):
		facts[i] = (facts[i-1] * i)% mod
		invs[i] = inv(facts[i])

factorial(MAX)
def nCr(n,r):
	return facts[n]*invs[r] * invs[n-r] % mod

h,w,th,ty = map(int,raw_input().split())

ans = 0

for i in range(ty+1,w+1):
	
	ans += (nCr(h-th-1 + i-1,i-1)%mod * nCr(th-1 + w-i,w-i)%mod)%mod

print ans%mod
