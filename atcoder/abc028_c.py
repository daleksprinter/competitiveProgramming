import itertools
arr = map(int,raw_input().split())

results = []
for item in itertools.combinations(range(5),3):
	results.append(arr[item[1]]+arr[item[0]]+arr[item[2]])

results.sort()

print results[-3]
