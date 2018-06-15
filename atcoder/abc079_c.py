arr = map(int,list(raw_input()))

printed = False

def comb(strs,sums,i):
		global printed
		if i == 3 and sums == 7 and not printed: 
			print str(arr[0]) + strs[0] + str(arr[1]) + strs[1] + str(arr[2]) + strs[2] + str(arr[3]) + "=7"
			printed = True

		elif i < 3:
			comb(strs+'+',sums+arr[i+1],i+1)
			comb(strs+'-',sums-arr[i+1],i+1)



comb('',arr[0],0)
