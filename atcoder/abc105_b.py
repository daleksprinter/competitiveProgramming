n = int(input())

for i in range(1000):
	for j in range(1000):
		if 4*i + 7*j == n:
			print 'Yes'
			quit()

print 'No'
