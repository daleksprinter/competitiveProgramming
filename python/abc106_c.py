s = map(int,list(raw_input()))

k = int(input())

t = -1

for i in range(len(s)):
	if s[i] == 1:
		t = i

	else :
		break

if t > -1 and k-1 <= t:
	print 1

else :
	print s[t+1]
