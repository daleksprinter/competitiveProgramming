import sys

sys.setrecursionlimit(10**5+100)
n = int(input())

edges = [[] for _ in xrange(n)]
distance = [-1 for _ in xrange(n)]

for _ in xrange(n-1):
	f,t,c = map(int,raw_input().split())

	f -= 1
	t -= 1

	edges[f].append((t,c))
	edges[t].append((f,c))

q,k = map(int,raw_input().split())
k -= 1

def dfs(v,c):
	if distance[v] == -1:
		distance[v] = c
		for to,cost in edges[v]:
			dfs(to,c+cost)

dfs(k,0)

for _ in xrange(q):
	x,y = map(int,raw_input().split())
	x -= 1
	y -= 1
	print distance[x] + distance[y]

