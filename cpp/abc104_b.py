s = raw_input()

if s[0] != 'A':
	print 'WA'
	quit()

ans = 0
for i in range(2,len(s)-1):
	if s[i] == 'C':
		ans += 1



if ans != 1:
	print 'WA'
	quit()

count = 0
for i in range(len(s)):
	if ord('a') <= ord(s[i]) <= ord('z') :
		count += 1

if count != len(s) - 2:
	print "WA"
	quit()

print "AC"
