n = int(input())
ans = 0
for i in range(n):
  f,t = map(int,raw_input().split())
  ans += (t - (f -1))

print ans
