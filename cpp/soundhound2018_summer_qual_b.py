s= raw_input()

w = int(input())

i = 0
ans = ""
while w*i < len(s):
	ans += s[w*i]
	i+= 1

print ans
