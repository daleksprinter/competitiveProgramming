a,b,c = map(int,raw_input().split())

if a == b and b == c :
	print 0 if a %2 == 1 else -1

else : 
	count = 0
	while True:
		if a % 2 == 1 or b%2 == 1 or c%2 ==1:
			print count 
			break
		else :
			a_tmp = b/2 + c/2
			b_tmp = a/2 + c/2
			c_tmp = a/2 + b/2
			a = a_tmp
			b = b_tmp
			c = c_tmp
			count += 1

