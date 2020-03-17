import numpy as np
n = int(input())

arr = map(int,raw_input().split())
arr.sort()
cs = np.cumsum(arr)

ans = 1

i = n-2
while i > -1 and cs[i] * 2 >= arr[i+1]:
	ans += 1
	i -= 1

print ans

