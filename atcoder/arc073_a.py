n, t = map(int,raw_input().split())

arr = map(int,raw_input().split())

ans = 0
for i in range(n-1):
	if arr[i] + t > arr[i+1]:
		ans += arr[i+1]-arr[i]

	else :
		ans += t

print ans+t


