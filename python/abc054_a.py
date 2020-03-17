a = [2,3,4,5,6,7,8,9,10,11, 12,13, 1]

alice, bob = map(int, raw_input().split())

if a.index(alice) > a.index(bob):
	print "Alice"

elif a.index(alice) < a.index(bob):
	print "Bob"
else:
	print "Draw"
