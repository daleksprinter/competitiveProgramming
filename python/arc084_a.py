import bisect

n = int(input())
a = map(int,raw_input().split())
a.sort()
b = map(int,raw_input().split())
b.sort()
c = map(int,raw_input().split())
c.sort()

count = 0
for i in b:
	count += bisect.bisect_left(a,i)*(n-bisect.bisect_right(c,i))

print count 
