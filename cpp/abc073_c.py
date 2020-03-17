n = int(input())

dic = {}
for i in range(n):
	tmp = int(input())
	if dic.has_key(tmp):
		dic[tmp] += 1
	else :
		dic[tmp] = 1

count = 0 
for i in dic.values():
	count += i%2

print count
