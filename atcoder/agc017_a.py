import math
n, p = map(int,raw_input().split())

arr = map(int,raw_input().split())

odd = 0
even = 0

for i in range(n):
	if arr[i] %2 == 0 :
		even += 1
	else :
		odd += 1

def P(n, r):
	return math.factorial(n)//math.factorial(n-r)

def C(n, r):
	return P(n, r)//math.factorial(r)

oddnum = 0
for i in range(1,odd+1,2):
	oddnum += C(odd,i)

if p == 1:
	print oddnum * 2**even
else :
	print 2**n-(oddnum*2**even)
