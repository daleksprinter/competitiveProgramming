n = int(input())

dp = [i for i in range(101010)]


t = 20

while True:
	for i in range(101010):
		if 6**t+(i+1) < 101010:
			dp[6**t+(i)] = min(dp[6**t+(i)], dp[i] + 1)

	t -= 1
	if t == 0:
		break

t = 20
while True:
	for i in range(101010):
		if 9**t+(i+1) < 101010:
			dp[9**t+(i)] = min(dp[9**t+(i)], dp[i] + 1)

	t -= 1
	if t == 0:
		break

i = 0
while i+1 < 101010:
	dp[i+1] = min(dp[i+1],dp[i]+1)
	i += 1

print dp[n]
