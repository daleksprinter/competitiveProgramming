n,k = map(int,raw_input().split())

arr = map(int,raw_input().split())

ans = float("inf")
import bisect
t = bisect.bisect_right(arr,0)
arr.insert(t,0)
for i in range(n+1):
	if i-k > -1:
		ans = min(ans, abs(arr[i-k]) + abs(arr[i]) + min(abs(arr[i-k]), abs(arr[i])))

print ans
