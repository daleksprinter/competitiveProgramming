n = int(input())

arr = map(int,raw_input().split())

sums = [0 for i in range(n)]

for i in range(n):
	sums[arr[i]] += 1


isprinted = False
mod = 1000000007
if n%2 == 1:
	if sums[0] == 1:
		for i in range(2,n,2):
			if sums[i] != 2:
				print 0
				isprinted = True
				break

		if not isprinted :
			print 2**((n-1)/2)%mod
	else :
		print 0

else :
	for i in range(1,n,2):
		if sums[i] != 2:
			print 0
			isprinted = True
			break

	if not isprinted:
		print 2**(n/2)%mod
