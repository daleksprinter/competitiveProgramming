import math
n,h = map(int,raw_input().split())

arra = []
arrb = []


for i in range(n):
	a , b = map(int,raw_input().split())
	arra.append(a)
	arrb.append(b)

arrb.sort()

l = len(arrb) - 1 
m = max(arra)
count = 0
while arrb[l] > m and -1 < l and h > 0:
	h = max(0,h-arrb[l])
	l -= 1
	count += 1

print count + -(h*-1 // m)


