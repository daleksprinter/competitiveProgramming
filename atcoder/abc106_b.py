n = int(input())

ans = 0
for i in range(1,n+1):
	if i %2 == 0 :
		continue
	count = 0
	for j in range(1,n+1):

		if i%j == 0:
			count += 1
		

	if count == 8:
		ans += 1

print ans
