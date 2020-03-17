n,k = map(int,raw_input().split())

arr = map(int,raw_input().split())
if k > max(arr):
	print "IMPOSSIBLE"
	quit()

def gcd(a,b):
	if b == 0 :
		return a
	else :
		return gcd(b,a%b)

g = arr[0]

for i in range(1,n):
	g = gcd(g,arr[i])

if k%g == 0 :
	print "POSSIBLE"

else :
	print "IMPOSSIBLE"

