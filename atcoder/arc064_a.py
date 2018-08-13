n,m = map(int,raw_input().split())

arr = map(int,raw_input().split())

ans = 0
for i in range(1,n):
	if arr[i] + arr[i-1] > m:
		t = min(arr[i],arr[i] + arr[i-1]-m)
		arr[i] -= t
		ans += t

	if arr[i] + arr[i-1] > m:
		t = min(arr[i-1],arr[i-1]-m)
		arr[i-1] -= t
		ans += t

print ans
