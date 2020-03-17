import re
s = raw_input()

if len(s) > 9 :
	print 'NO'
	quit()

else:
	m = re.match(r"A?KIHA?BA?RA?",s)
	if m :
		print 'YES'
	else:
		print 'NO'
