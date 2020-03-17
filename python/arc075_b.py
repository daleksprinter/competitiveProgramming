n,a,b = map(int,raw_input().split())

arr = []

for i in range(n):
	arr.append(int(input()))

def ceil(a,b):
	if a % b == 0:
		return a/b
	else :
		return a/b + 1

def istrue(x):
	t = 0
	for i in arr:
		t += ceil((i - (b*x) if (i - (b*x)) > 0 else 0),(a-b))

	if t <= x :
		return True 

	else :
		return False


left = 0; right = 10**9
for i in range(30):
	mid = (left + right)/2
	if istrue(mid):
		right = mid
	else :
		left = mid

print right
