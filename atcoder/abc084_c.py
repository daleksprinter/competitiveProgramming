n = int(input())

arr = [map(int,raw_input().split()) for i in range(n-1)]

def ceil(n,d):
	if n%d==0:
		return n/d

	else:
		return n/d+1

for i in range(n):
	t = 0

	for j in range(i,n-1):
		c,s,f = arr[j]
		t = max(ceil(t,f)*f, s) + c


	print t

