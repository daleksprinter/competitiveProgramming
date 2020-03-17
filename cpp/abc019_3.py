n = int(input())

arr = map(int,raw_input().split())

dic = {}

for i in arr:
	t = i
	while t%2 == 0:
		t /= 2

	if t in dic :
		dic[t] += 1

	else :
		dic[t] = 1

print len(dic) 
