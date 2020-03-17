n = int(input())
arr = map(int,raw_input().split())

ans = 0
for i in range(n-1):
	if arr[i] == arr[i+1]:
		ans += 1
		arr[i+1] = -1

print ans


