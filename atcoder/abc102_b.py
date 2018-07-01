n = int(input())

arr = map(int,raw_input().split())


ans = 0
for i in range(n):
	for j in range(n):
		if i != j:
			ans = max(ans,abs(arr[i]-arr[j]))

print ans
