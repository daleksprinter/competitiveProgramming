import numpy

n = int(input())

arr = map(int,raw_input().split())

sumarr = numpy.cumsum(arr)
l = len(sumarr)
ans = float("inf")
for i in range(n-1):
	ans = min(ans,abs(sumarr[l-1]-2*sumarr[i]))

print ans

