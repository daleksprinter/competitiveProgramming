n = int(input())

arr = map(int,raw_input().split())

dp = [[-1 for i in range(10001)] for j in range(n+1)]

dp[0][0] = 0

for i in range(n):
	for j in range(10001):
		if dp[i][j] != -1 and j+arr[i] < 10001:
			dp[i+1][j] = 0
			dp[i+1][j + arr[i]] = 0


print dp[n].count(0)
