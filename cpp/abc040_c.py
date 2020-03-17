n = int(input())

arr = map(int,raw_input().split())

dp = []

dp.append(0)
dp.append(abs(arr[0] - arr[1]))

for i in range(2,n):
	dp.append(min( dp[i-2] + abs(arr[i]-arr[i-2]) , dp[i-1] + abs(arr[i]-arr[i-1]) ))

print dp[n-1]
