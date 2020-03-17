s = raw_input()
k = int(input())
l = len(s)
arr = []

for i in range(l):
	for j in range(1,min(6,l-i+1)):
		arr.append(s[i:i+j])

arr_uni = list(set(arr))
arr_uni.sort()
print arr_uni[k-1]


