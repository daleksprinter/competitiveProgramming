n,m,d = map(int,raw_input().split())

print (((n-d)*2)/float(n**2))*(m-1) if d != 0 else ((((n-d)*2)/float(n**2))*(m-1))/2
