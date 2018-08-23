s = raw_input()

l = 0
r = len(s)-1

ans = 0
while l <= r and -1 < l < len(s) and -1 < r < len(s):
	if s[l] == s[r]:
		l += 1
		r -= 1

	else :
		if s[l] == "x":
			l += 1
			ans += 1
		elif s[r] == "x":
			r -= 1
			ans += 1

		else :
			print -1
			quit()
	
print ans 

