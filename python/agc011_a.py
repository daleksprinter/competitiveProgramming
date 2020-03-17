n,c,k = map(int,raw_input().split())


t = []
for i in range(n):
	t.append(int(input()))

t.sort()

ans = 0
depart = t[0]
people = 0

i = 0
while i < n:
	if t[i] <= depart + k and people < c :
		people += 1
		i += 1

	else :
		ans += 1
		people = 0
		depart = t[i]

print ans + 1

