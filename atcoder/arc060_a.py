n,a = map(int,raw_input().split())

arr = map(int,raw_input().split())
arry = []

for i in range(n):
	arry.append(arr[i]-a)


dp = [[0 for i in range((n)*50*2)] for j in range(n+1)]
dp[0][n*50] = 1

for i in range(n):
	for j in range(n*50*2):
		if 0 <= j-arry[i] and j-arry[i] < n*50*2 :
			dp[i+1][j] = dp[i][j]+dp[i][j-arry[i]]
		else :
			dp[i+1][j] = dp[i][j]

print dp[n][n*50]-1
