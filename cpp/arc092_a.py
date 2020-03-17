n = int(input())

red = []

for i in range(n):
	red.append(map(int,raw_input().split()))

blue = []

for i in range(n):
	blue.append(map(int,raw_input().split()))


redflug = []
for i in range(n):
	redflug.append(0)

blue.sort()

ans = 0
for i in range(n):
	t = -1
	maxy = -1
	for j in range(n):
		if redflug[j] == 0 and blue[i][0] > red[j][0] and blue[i][1] > red[j][1] and red[j][1] > maxy :
			t = j
			maxy = red[j][1]

	if t != -1 :
		redflug[t] = 1
		ans += 1

print ans
