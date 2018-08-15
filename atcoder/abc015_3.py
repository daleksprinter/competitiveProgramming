n,m = map(int,raw_input().split())

arr = []
for i in range(n):
	arr.append(map(int,raw_input().split()))

def dfs(i,depth):
	if depth == n:
		if i == 0:
			print 'Found'
			quit()

	else :
		for j in range(m):
			dfs(i ^ arr[depth][j],depth +1)
dfs(0,0)
print 'Nothing'

