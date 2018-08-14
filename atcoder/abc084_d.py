import bisect
def mark(s, x):
    for i in xrange(x + x, len(s), x):
        s[i] = False

def sieve(n):
    s = [True] * n
    for x in xrange(2, int(n**0.5) + 1):
        if s[x]: mark(s, x)
    return [i for i in xrange(0,n) if s[i] and i > 1]


primes = sieve(10**5)
likes = []
for i in primes:
	if primes[bisect.bisect_left(primes,(i+1)/2)] == (i+1)/2:
		likes.append(i)

cs = [0 for i in range(10**5+1)]

i = 1
j = 0

while i < 10**5+1 and j < len(likes):
	if likes[j] > i:
		cs[i] = cs[i-1]

	else:
		cs[i] = cs[i-1]+1
		j +=1
	i += 1
t = cs[i-1]
while i < 10**5+1:
	cs[i] = t
	i += 1

q = int(input())

for i in range(q):
	l,r = map(int,raw_input().split())
	print cs[r+1]- cs[l-1]
