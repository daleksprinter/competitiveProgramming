n = int(input())

arr = [map(int,raw_input().split()) for i in range(2)]

ans = [[0 for i in range(n)] for j in range(2)]

ans[0][0] = arr[0][0]
ans[1][0] = arr[0][0] + arr[1][0]

for i in range(n-1):
	ans[0][i+1] = ans[0][i] + arr[0][i+1]

for i in range(n-1):
	ans[1][i+1] = max(ans[0][i+1] + arr[1][i+1], ans[1][i] + arr[1][i+1])

print ans[1][n-1]
