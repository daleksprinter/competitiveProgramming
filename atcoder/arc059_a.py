n = int(input())

arr = map(int,raw_input().split())

ma = max(arr)
mi = min(arr)

ans = float("inf")

for i in range(mi,ma+1):
	count = 0
	for j in range(n):

		count += (i - arr[j]) * (i - arr[j])

	ans = min(ans,count)

print ans
