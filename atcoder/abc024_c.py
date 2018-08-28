n,d,k = map(int,raw_input().split())

arr = [map(int,raw_input().split()) for _ in xrange(d)]

for _ in xrange(k):
	f,t = map(int,raw_input().split())
	tmp = f

	if f < t:
		for i in xrange(d):
			x, y = arr[i]

			if x <= tmp <= y:
				tmp = y

			if t <= tmp:
				print i+1
				break

	else :
		for i in xrange(d):
			x,y = arr[i]
			if x <= tmp <= y:
				tmp = x

			if tmp <= t:
				print i+1
				break
