import sys
s = raw_input()
t = raw_input()

ls = len(s)
lt = len(t)
if ls < lt :
	print 'UNRESTORABLE'
	sys.exit()

for i in range(ls-lt,-1,-1):
	count = 0
	for j in range(lt):
		if s[i+j] == '?' or s[i+j] == t[j]:
			count += 1
		else :
			break
	if count == lt:

		print s[:i].replace('?','a')+t+s[i+lt:].replace('?','a')
		sys.exit()

print 'UNRESTORABLE'

