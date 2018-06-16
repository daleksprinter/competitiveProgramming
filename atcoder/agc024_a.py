a,b,c,k = map(int,raw_input().split())

if k%2 == 0:
	print a - b if abs(a-b) < 10**18 else 'Unfair'

else :
	print b - a if abs(a-b) < 10**18 else 'Unfair'

