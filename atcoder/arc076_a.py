
mod = 10**9+7
n,m = map(int,raw_input().split())
def factorial(x):
	retval = 1
	for i in range(2,x+1):
		retval = (retval * i)% mod
	return retval

if abs(n-m) > 1:
	print 0
	quit()

if max(n,m) > min(n,m):
	print (factorial(max(n,m)) * factorial(min(n,m))) % mod

else :
	print ((factorial(n)**2)%mod * 2)%mod
