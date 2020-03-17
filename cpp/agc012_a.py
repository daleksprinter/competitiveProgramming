n = int(input())

arr = map(int,raw_input().split())

arr.sort()

ans = 0 
for i in range(3*n-2,n-1,-2):
	ans += arr[i]

print ans
