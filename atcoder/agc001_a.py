n = int(input())

arr = map(int,raw_input().split())

arr.sort()

count = 0
for i in range(n):
	count += arr[i*2]

print count

