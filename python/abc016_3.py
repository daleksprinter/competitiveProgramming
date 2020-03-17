n,m = map(int,raw_input().split())

arr = [[float("inf") for i in range(n)] for j in range(n)]

for i in range(n):
	arr[i][i] = 0

for i in range(m):
	f,t = map(int,raw_input().split()); f -= 1; t -= 1
	arr[f][t] = 1
	arr[t][f] = 1

for k in range(n):
	for i in range(n):
		for j in range(n):
			arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j])


for i in arr:
	count = 0
	for j in i:
		if j == 2 : 
			count += 1

	print count 
