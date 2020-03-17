l = map(int,raw_input().split())

cost = map(int,raw_input().split())

arr = [map(int,raw_input().split()) for i in range(2)]

ans = 0

pos = [0,0]
p = 0

while True :

	while pos[(p+1)%2] < l[(p+1)%2] and arr[p][pos[p]] + cost[p] > arr[(p+1)%2][pos[(p+1)%2]]:
		pos[(p+1)%2] += 1

	if p == 1 :
		ans += 1

	p = (p+1)%2

	if pos[0] >= l[0] or pos[1] >= l[1]:
		break
print ans
