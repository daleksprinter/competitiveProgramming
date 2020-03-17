n = int(input())

a = map(int,raw_input().split())
b = map(int,raw_input().split())

combs = [0 for i in range(n)]
unique = [0 for i in range(n)]
t = 0
mod = 10**9 + 7
for i in range(n):
	if a[i] > t or a[i] == 1:
		combs[i] = 1
		t = a[i]
		unique[i] = 1

	else :
		combs[i] = t
t = 0
for i in range(n-1,-1,-1):
	if unique[i] == 1 and a[i] > b[i] :
		print 0
		quit()

	if b[i] > t:
		combs[i] = 1
		t = b[i]

	else :
		combs[i] = min(combs[i], t)

ans = 1
for i in combs:
	ans = (ans * i)%mod

print ans
