n = int(input())

def ceil(a,b):
	if a%b == 0:
		return a/b
	else:
		return a/b + 1

if n% 2 == 0:
	print (n/2 )**2

else :
	print n/2 * ((n/2)+1)
