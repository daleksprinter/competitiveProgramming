n,k = map(int,raw_input().split())

arr = [0,1,2,3,4,5,6,7,8,9]
r = map(int,raw_input().split())

for i in r:
	arr.remove(i)


def count_digit(num):
	count = 0
	t = num 
	while t > 0 :
		count += 1
		t /= 10
	return count

dc = count_digit(n) + 1


ans = float("inf")

def dfs(s,i):
	global ans,n,dc
	
	ret = int(s) if i > 0 else 0
	if ret >= n :
		ans = min(ans,ret)

	if i != dc :
		for j in arr :
			dfs(s + str(j),i + 1)

dfs('',0)
print ans
