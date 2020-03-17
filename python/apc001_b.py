n = int(input())

a = map(int,raw_input().split())
b = map(int,raw_input().split())

a_t = 0
b_t = 0

for i in range(n):
	if a[i] > b[i] :
		a_t += (a[i] - b[i])

	else:
		b_t += (b[i]-a[i])/2

print 'Yes' if a_t <= b_t else 'No'
