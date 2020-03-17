import collections
n = int(input())

arr = map(int,raw_input().split())
l = len(arr)
counter = collections.Counter(arr)

c = 0

for item in counter.items() :
	if item[1] > 2:
		if item[1] % 2 == 1 :
			l -= item[1] - 1

		else:
			l -= item[1] - 2

	if item[1] % 2 == 0 :
		c += 1

if c % 2 == 0:
	l -= c

else :
	l -= c+1

print l

