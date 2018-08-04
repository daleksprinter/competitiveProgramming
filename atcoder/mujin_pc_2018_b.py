a = int(input())

s = raw_input()

if a == 0:
	print 'Yes'
	quit()

for i in range(len(s)):
	if s[i] == '-':
		a -= 1
	else :
		a += 1

	if a == 0:
		print 'Yes'
		quit()

print 'No' 
