n,k = map(int,raw_input().split())

arr = map(int,raw_input().split())
arr.sort()

ans = 0
for i in range(n-k,n):
	ans = (ans+arr[i])/2.0

print ans
