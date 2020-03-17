import numpy as np
n = int(input())

arr = map(int,raw_input().split())

cs = np.cumsum(arr)

to = [1,-1]

def digit(n):
	if n > 0:
		return 1
	elif n < 0:
		return -1
	else :
		return 0

tmp1 = 0
ans1 = 0
p = 0
for i in range(n):
	x = cs[i] + tmp1
	if digit(x) != to[p]:
		tmp1 += to[p] - x
		ans1 += abs(to[p] - x)

	p = (p+1)%2

tmp2 = 0
ans2 = 0
p = 1
for i in range(n):
	x = cs[i] + tmp2
	if digit(x) != to[p]:
		tmp2 += to[p] - x
		ans2 += abs(to[p] - x)
	p = (p+1) %2


print min(ans1,ans2)

