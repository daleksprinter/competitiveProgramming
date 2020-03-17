import numpy as np
n,m,q = map(int,raw_input().split())

imos = [[0 for i in xrange(n)] for j in xrange(n)]

for i in xrange(m):
	f,t = map(int,raw_input().split())
	f -= 1
	t -= 1
	imos[f][t] += 1

for i in range(n-1,0,-1):
	for j in range(n):
		imos[i-1][j] = imos[i][j] + imos[i-1][j]

for i in xrange(n):
	imos[i] = np.cumsum(imos[i])

for i in xrange(q):
	a,b = map(int,raw_input().split())
	print imos[a-1][b-1]
