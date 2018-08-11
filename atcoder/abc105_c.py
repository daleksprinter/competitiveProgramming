n = int(input())
if n == 0:
	print '0'
	quit()
ans = ''
while n :
	
	if n%(-2) == 0 :
		ans += '0'
	else :
		ans += '1'
	n += (n%(-2))
	n/= (-2)

print ans[::-1]
