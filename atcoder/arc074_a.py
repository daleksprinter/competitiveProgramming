import numpy as np
h,w = map(int,raw_input().split())

ans = float("inf")

def div(h,w):
	def yokoyoko(a,b):
		if a != 0 and a != h and b != 0 and b!= h:
			global ans
			c = h-a-b
			ans = min(ans,max(abs(a*w-b*w),abs(a*w-c*w),abs(c*w-b*w)))

	def yokotate(a,b):
		if a != 0 and a!= h and b!= 0 and b != w:
			global ans
			tate = h-a
			ans = min(ans,max(abs(a*w-tate*b),abs(a*w-tate*(w-b)),abs(tate*b-tate*(w-b))))

	a1 = np.floor(h/3.0)

	byoko1 = np.floor((h-a1)/2.0)
	yokoyoko(a1,byoko1)

	byoko2 = np.ceil((h-a1)/2.0)
	yokoyoko(a1,byoko2)

	btate1 = np.floor(w/2.0)
	yokotate(a1,btate1)

	btate2 = np.ceil(w/2.0)
	yokotate(a1,btate2)


	a2 = np.ceil(h/3.0)

	byoko1 = np.floor((h-a2)/2.0)
	yokoyoko(a2,byoko1)

	byoko2 = np.ceil((h-a2)/2.0)
	yokoyoko(a2,byoko2)

	yokotate(a2,btate1)
	yokotate(a1,btate2)
	
div(h,w)
div(w,h)

print int(ans)
