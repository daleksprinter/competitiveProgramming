n,m = map(int,raw_input().split())

arr = []

for i in range(n):
	arr.append(map(int,raw_input().split()))

v = [[1,1,1],[1,1,-1],[1,-1,-1],[1,-1,1],[-1,-1,-1],[-1,1,1],[-1,1,-1],[-1,-1,1]]

ans = 0

for i in range(8):
	tmp = []
	for j in range(n):
		tmp.append(arr[j][0] * v[i][0] + arr[j][1] * v[i][1] + arr[j][2] * v[i][2])

	tmp.sort()
	ans = max(ans,sum(tmp[n-m:]))

print ans


