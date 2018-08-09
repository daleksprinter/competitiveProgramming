n = int(input())

arr = []
arr.append(map(int,raw_input().split()))
arr.append(map(int,raw_input().split()))

dp = [[0 for i in range(n)] for j in range(2)]

dp[0][0] = arr[0][0]
for i in range(1,n):
	dp[0][i] = dp[0][i-1] + arr[0][i]

dp[1][0] = dp[0][0] + arr[1][0]

for i in range(1,n):
	dp[1][i] = max(dp[1][i-1] + arr[1][i],dp[0][i] + arr[1][i])

print dp[1][n-1]
