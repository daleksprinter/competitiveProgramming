import math
def mark(s, x):
    for i in xrange(x + x, len(s), x):
        s[i] = False

def sieve(n):
    s = [True] * n
    for x in xrange(2, int(n**0.5) + 1):
        if s[x]: mark(s, x)
    return [i for i in xrange(0,n) if s[i] and i > 1]

n = int(input())

arr = sieve(n+1)
f = math.factorial(n)

primes = [0 for i in range(n+1)]


for i in arr:
	while f%i == 0:
		f/= i
		primes[i] += 1

ans = 1
for i in primes:
	if i!= 0:
		ans *= i+1

print ans%(10**9+7)
