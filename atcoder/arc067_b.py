n,a,b = map(int,raw_input().split())

arr = map(int,raw_input().split())

ans = 0

for i in range(1,n):
	ans += min(b,(arr[i] - arr[i-1])*a)

print ans
