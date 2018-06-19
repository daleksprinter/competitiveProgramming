s = raw_input()
n = len(s)
i = 1
now = s[0]
count = 0
while i < n:
	if s[i] != now:
		now = s[i]
		i += 1
		count += 1
	else:
		i += 1

print count 
