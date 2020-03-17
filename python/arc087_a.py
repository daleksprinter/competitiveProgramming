import collections
n = int(input())

arr = map(int,raw_input().split())

counter = collections.Counter(arr)

ans = 0 

for item in counter.items() :
	if item[0] == item[1]:
		next

	elif item[1] < item[0]:
		ans += item[1]

	else :
		ans += item[1]-item[0]

print ans

