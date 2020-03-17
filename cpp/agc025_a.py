n = int(input())

def digitsum(x):
	tmp = x
	ans = 0
	while tmp > 0:
		ans += tmp % 10
		tmp /= 10

	return ans

ans = float("inf")
for i in range(1,(n/2)+1):
	ans = min(ans,digitsum(i) + digitsum(n-i))

print ans
