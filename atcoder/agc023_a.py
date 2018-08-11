import numpy,collections
n = int(input())

arr = map(int,raw_input().split())

cs = [0]
cs.extend(numpy.cumsum(arr))
count = collections.Counter(cs)

ans = 0
for i in count.values():
	ans += i*(i-1)/2

print ans
