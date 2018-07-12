n = int(input())

arr = map(int,raw_input().split())

odd = 0

for i in range(n):
	if arr[i] % 2 == 1:
		odd += 1

print 'YES' if odd % 2 == 0 else 'NO'

