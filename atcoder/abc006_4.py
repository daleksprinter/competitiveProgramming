import bisect
n = int(input())
inf = float("inf")
arr = [int(input()) for _ in xrange(n)]

dp = [inf for _ in xrange(n)]

for i in arr:
	ind = bisect.bisect_left(dp,i)
	dp[ind] = i

print n - bisect.bisect_left(dp,inf)
