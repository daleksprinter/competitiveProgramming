n,m = map(int,raw_input().split())

if n == 1 or m == 1:
	print abs(n*m-2)

elif n==2 or m==2:
	print 0

else :
	print n*m-(2*n+2*m-4)
