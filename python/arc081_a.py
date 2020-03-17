n = int(input())

arr = map(int,raw_input().split())

arr.sort()

i = n-1

lines = []

while i > 0 and len(lines) < 2:
	if arr[i] == arr[i-1]:
		lines.append(arr[i])
		i -= 2
		next

	else :
		i -= 1

if len(lines) == 2:
	print lines[0] * lines[1]

else :
	print 0
