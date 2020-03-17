n = int(input())

t = n 
a = 0
while t > 0 :
	a+= t%10
	t/= 10

print 'Yes' if n%a == 0 else 'No'
