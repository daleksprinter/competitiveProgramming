n = int(input())

arr = map(int,raw_input().split())

ans = 0

for i in range(n-1):
	if arr[i] == i+1:
		arr[i],arr[i+1] = arr[i+1],arr[i]
		ans += 1

print ans if arr[n-1] != n else ans + 1
