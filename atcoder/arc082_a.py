n = int(input())

arr = map(int,raw_input().split())

dic = [0 for i in range(10**5)]

for i in arr:
	dic[i] += 1

ans = 0
for i in range(10**5-2):
	ans = max(ans,dic[i]+dic[i+1]+dic[i+2])

print ans
