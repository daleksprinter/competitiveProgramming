def count(line):
	count = 0
	if (line[0]+line[1]+line[2])%2 == 0:
		flag = False
		for i in range(3) :
			if line[i]%2 == 1 :
				line[i] += 1
				flag = True

		if flag == True:
			count += 1
		
		max = 0
		
		for i in range(3):
			if max < line[i]:
				max = line[i]
		for i in range(3):
			count += (max - line[i])/2
		return count
	else :
		flag = False
		for i in range(3):
			if line[i]%2 == 0:
				line[i] += 1
				flag = True
		if flag == True:
			count+= 1
		max = 0
		for i in range(3):
			if max<line[i]:
				max =line[i]
		for i in range(3) : 
			count += (max-line[i])/2
		return count

print count(map(int,raw_input().split()))
