n = int(input())

arr = map(int,raw_input().split())

arrb = arr[:]
arrb.sort()
a = n/2-1
b = n/2

for i in range(n):
	if arr[i] >= arrb[b]:
		print arrb[a]
	else :
		print arrb[b]
