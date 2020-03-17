n = int(input())

rejected = []

for i in range(3):
	rejected.append(int(input()))


dp = [float("inf") for i in range(n+1)]

for i in range(3):
	if rejected[i] < n+1:
		dp[rejected[i]] = -1


if dp[n] == -1:
	print 'NO'
	quit() 

dp[n] = 0

i = n

while i > 0 :
	if dp[i] != -1:
		for j in range(1,4):
			if  i-j > -1 :
				dp[i-j] = min(dp[i-j], dp[i] + 1)

	i -= 1

print 'YES' if dp[0] <= 100 else 'NO'
