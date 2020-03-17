import numpy as np
n = int(input())

arr = map(int,raw_input().split())

arrb = []

for i in range(n):
	arrb.append(arr[i]-i)

med = np.median(arrb)

ans = 0
for i in range(n):
	ans += abs(arrb[i]-med)

print int(ans)
