n = int(input())

maxm = 10**6+1
arr = [0 for i in range(maxm)]

for i in range(n):
	f,t = map(int,raw_input().split())

	arr[f] += 1
	if t + 1 < maxm : 
		arr[t+1] -= 1

import numpy
cs = numpy.cumsum(arr)

print max(cs)

