h,w = map(int,raw_input().split())
d = [map(int,raw_input().split()) for i in range(10)]
for t in xrange(10):
	for i in range(10):
		for j in range(10):
			for k in range(10):
				d[i][j] = min(d[i][j], d[i][k] + d[k][j])
arr = [map(int,raw_input().split()) for i in range(h)]

print sum(sum(d[a][1] if a>=0 else 0 for a in aa) for aa in arr)
