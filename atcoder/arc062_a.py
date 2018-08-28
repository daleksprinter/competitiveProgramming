n = int(input())

arr = [map(int,raw_input().split()) for i in range(n)]

def ceil(n,d):
 if n%d==0:
  return n/d
 else:
  return n/d+1

a = 1
b = 1
for i in range(n):
	x, y = arr[i]
	t = max(ceil(a,x), ceil(b,y))

	a = x*t; b = y*t

print a+b
