n = int(input())

def bfa(s,i):
	if i == n:
		print s
	else :
		bfa(s+'a',i+1)
		bfa(s+'b',i+1)
		bfa(s+'c',i+1)

bfa('',0)
