n,m = map(int,raw_input().split())

stomid = [0]*n
midtog = [0]*n

for i in range(m):
	f,t = map(int,raw_input().split())
	if f == 1:
		stomid[t-1] = 1

	elif t == n:
		midtog[f-1] = 1 

for i in range(n):
	if stomid[i] == midtog[i] == 1 :
		print 'POSSIBLE'
		quit()

print 'IMPOSSIBLE'
