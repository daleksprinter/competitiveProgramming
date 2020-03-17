import itertools 
n,c = map(int,raw_input().split())
d = [map(int,raw_input().split()) for i in range(c)]
arr = [map(int,raw_input().split()) for i in range(n)]
coltable = [[0 for j in range(c)] for i in range(3)]

for i in range(n):
	for j in range(n):
		coltable[((i+1) + (j+1))%3][arr[i][j]-1] += 1

perm = list(itertools.permutations(range(c),3))

ans = float("inf")




for i in perm:
	point = 0

	for j in range(3):
		for k in range(c):
			point += d[k][i[j]] * coltable[j][k]


	ans = min(ans,point)

print ans

