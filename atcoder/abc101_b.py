n = raw_input()
lis = list(n)

ans = 0
for i in range(len(n)):
	ans += int(lis[i])

if int(n)%ans == 0:
	print 'Yes'
else :
	print 'No'

