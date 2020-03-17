import sys
s = raw_input()

t = raw_input()


l = len(s)
for i in range(l):

	if s[i:] + s[:i] == t:
		print 'Yes'
		sys.exit()

print 'No'
