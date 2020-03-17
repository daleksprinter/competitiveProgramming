import sys
s = list(raw_input())

l = len(s)

if l == 2:
	if s[0] == s[1]:
		print "1 2"
		sys.exit()

	else:
		print '-1 -1'
		sys.exit()

for i in range(l-2):
	t = []
	for j in range(3):
		if s[i + j] in t:
			print i+1,i+3
			sys.exit()
		else :
			t.append(s[i + j])

print "-1 -1"
