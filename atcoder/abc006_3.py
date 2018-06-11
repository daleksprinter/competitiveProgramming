n,m = map(int,raw_input().split())

isans = False
for i in range(n+1):
	if 2*i + 4*(n-i-1) == m-3 and n-i-1 >= 0:
		print '%d %d %d' %(i,1,n-i-1)
		isans = True
		break
	elif 2*i + 4*(n-i) == m :
		print '%d %d %d' %(i,0,n-i)
		isans = True
		break

if not isans:
	print '-1 -1 -1'
