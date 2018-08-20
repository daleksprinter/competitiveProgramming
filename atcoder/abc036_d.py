n = int(input())

e = [[] for i in range(n)]
edge = [[] for i in range(n)]


for i in range(n-1):
	f,t = map(int,raw_input().split())

	f -= 1
	t -= 1

	e[f].append(t)
	e[t].append(f)

def dfs(v,p):
	for i in e[v]:
		if i != p:
			edge[v].append(i)
			dfs(i,v)

dfs(0,-1)
mod = 10**9+7

dp = [[-1 for i in range(2)] for j in range(n)]
#black...0
#white...1
def comb(v,c):
	if dp[v][c] != -1 :
		return dp[v][c]
	res = 1
	if c == 0:
		for i in edge[v]:
			res *= comb(i,1)
			res %= mod
	else:
		for i in edge[v]:
			res *= comb(i,0) + comb(i,1)
			res %= mod
	dp[v][c] = res
	return res

print (comb(0,0)+comb(0,1))%mod
