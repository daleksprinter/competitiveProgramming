n,k = map(int,raw_input().split())
arr = map(int,raw_input().split())
print (n-1)/(k-1) + (0 if (n-1)%(k-1) == 0 else 1)
