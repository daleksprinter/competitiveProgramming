n = int(input())
arr = map(int,raw_input().split())

ans = 0

for i in range(n):
	ans += arr[i] - 1
print ans
