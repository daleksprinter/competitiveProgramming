import math
n = int(input())

arr = map(int,raw_input().split())

l = 0 
r = 0 

ans = 0
while r < n:
	while r+1 < n and arr[r+1] > arr[r]:
		r += 1

	ans += sum(range(r-l+2))
	r += 1
	l = r

print ans
