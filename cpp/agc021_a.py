n = map(int,list(raw_input()))

for i in range(1,len(n)):
	if n[i] != 9:
		print n[0] + (9*(len(n)-1)) - 1
		quit()

print sum(n)
