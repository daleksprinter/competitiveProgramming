n = int(input())

arr = map(int,raw_input().split())

count = 0
for i in range(n):
	while arr[i]%2 == 0:
		count+= 1
		arr[i]= arr[i]/2

print count 
