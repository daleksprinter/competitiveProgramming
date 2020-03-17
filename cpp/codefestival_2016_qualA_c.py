
aord = ord("a")
s = list(raw_input())
k = int(input())
i = 0

while k > 0 and i < len(s):
	if k >= ord('z') - ord(s[i]) + 1:
		if s[i] != "a":
			k -= ord('z') - ord(s[i]) + 1
			s[i] = "a"

	i += 1
k = k%26
s[len(s)-1] = chr(ord(s[len(s)-1]) + k)
print ''.join(s)
