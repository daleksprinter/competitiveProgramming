n,m = map(int,raw_input().split())

if n*m < 0 :
	print 'Zero'
elif n+m< 0 and abs(n-m)%2==0:
	print 'Negative'
else:
	print 'Positive'
