a,b = map(int,raw_input().split())
arr = []
arr.append(1)
for i in range(2,1000):
	arr.append(arr[i-2] + i)

sub = b-a

print arr[sub-1]-b

