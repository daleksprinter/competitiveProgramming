import sys
n,p = map(int,raw_input().split())
arr = map(int,raw_input().split())

l = 0 
r = 0 

ans = arr[0]

while r < n:
	if ans == p:
		print 'Yay!'
		sys.exit()

	elif r+1 < n and ans * arr[r+1] <= p:
		r += 1
		ans *= arr[r]

	else  :
		ans /= arr[l]
		l += 1
		if l == n:
			break



print ':('

