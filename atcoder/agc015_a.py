n,a,b = map(int,raw_input().split())

ans =  (a + b*(n - 1) ) - (a*(n-1) + b) + 1 
print ans if ans > 0 else 0
