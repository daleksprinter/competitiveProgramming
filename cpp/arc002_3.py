n = int(input())

s = raw_input()

command = ['A', 'B', 'X', 'Y']


ans = float("inf")
for l1 in command:
	for l2 in command:
		for r1 in command:
			for r2 in command:
				count = 0
				i = 0
				while i < n :
					if s[i:i+2] == (l1 + l2) or s[i:i+2] == (r1 + r2):
						count += 1
						i += 2
					else :
						count += 1
						i += 1

				ans = min(ans, count)

print ans
