n = int(input())
 
s = raw_input()
 
i = 0
left = 0
while i < len(s) and s[i] == 'A':
	i += 1
	left += i
if i == len(s):
	x = i*n
	print x*(x+1)/2
	quit()
 
right = 0
t = 0
for j in xrange(i,len(s)):
	if s[j] == 'A':
		t += 1
		right += t
 
	else :
		t = 0
roop = right
while i > 0:
	t += 1
	roop += t
	i -= 1
 
 
print left + roop * (n-1) + right
