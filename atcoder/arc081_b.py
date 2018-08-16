n = int(input())

s = raw_input()

arr = []

i = 0
while i < n:
	if i == n-1:
		arr.append('y')
		break

	if s[i] == s[i+1] :
		arr.append('x')
		i += 2

	else :
		arr.append('y')
		i += 1

ans = 3 if arr[0] == 'y' else 6

for i in range(1,len(arr)):
	if arr[i-1] == 'y' and arr[i] == 'y': 
		ans *= 2

	elif arr[i-1] == 'y' and arr[i] == 'x':
		ans *= 2

	elif arr[i-1] == 'x' and arr[i] == 'y':
		ans *= 1

	else :
		ans *= 3
print ans % (10**9 + 7)
