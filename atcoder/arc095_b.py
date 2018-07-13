import numpy as np
n = int(input())

arr = map(int,raw_input().split())

arr.sort()
mx = arr.pop()

def getNearestValue(list, num):
	idx = np.abs(np.asarray(list) - num).argmin()
	return list[idx]

print mx,getNearestValue(arr,mx/2.0)
