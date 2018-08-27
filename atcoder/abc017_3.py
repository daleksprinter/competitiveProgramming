import numpy as np
n,m = map(int,raw_input().split())

arr = [0] * m

for i in range(n):
	l,r,s = map(int,raw_input().split()); l-=1;r-= 1

	if l > 0:
		arr[0] += s
		arr[l] -= s
	if r < m-1:
		arr[r+1] += s


print max(np.cumsum(arr))
