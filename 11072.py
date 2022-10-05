from sys import stdin
from functools import cmp_to_key

p0, points = None, None

def distsq(p1, p2):
	return ((p2[0]-p1[0])**2) + ((p2[1]-p1[1])**2)

def orientation(p, q, r):
	val, ans = ((q[1]-p[1])*(r[0]-q[0])) - ((r[1]-q[1])*(q[0]-p[0])), None
	if val == 0: ans = 0
	elif val > 0: ans = 1
	else: ans = 2
	return ans

def compare(p1, p2):
	alpha, ans = orientation(p0, p1, p2), None
	if alpha == 0:
		if distsq(p0, p2) >= distsq(p0, p1): ans = -1
		else: ans = 1
	else:
		if alpha == 2: ans = -1
		else: ans = 1
	return ans

def convexhull(n):
	global p0, points
	min, ymin = 0, points[0][1]
	for i in range(1, n):
		(x,y) = points[i]
		if (y < ymin) or (y==ymin and x < points[min][0]): min, ymin = i, y
	points[0], points[min] = points[min], points[0]
	p0, m = points[0], 1
	points.sort(key=cmp_to_key(compare))
	for i in range(1, n):
		while (i < n-1) and (orientation(p0, points[i], points[i+1])==0): i += 1
		points[m], m = points[i], m+1
	S = [points[i] for i in range(3)]
	for i in range(3, m):
		while (len(S) > 1) and (orientation(S[-2], S[-1], points[i]) != 2): S.pop()
		S.append(points[i])
	if S[-1] == S[-2]: S.pop()
	return S

def phi(p, S):
	ans, i = True, 1
	while ans and i <= len(S):
		p1, p2 = S[i-1], None 
		if i == len(S): p2 = S[0]
		else: p2 = S[i]
		a = orientation(p1, p2, p)
		if a == 1: ans = False
		elif a == 0:
			xm, xM = min(p1[0], p2[0]), max(p1[0], p2[0])
			ym, yM = min(p1[1], p2[1]), max(p1[1], p2[1]) 
			if not (p[0] >= xm and p[0] <= xM and p[1] >= ym and p[1] <= yM): ans = False
		i += 1
	return ans

def main():
	global points
	try:
		for temp in stdin:
			if temp.strip() == "": continue
			n = int(temp)
			points = [None for _ in range(n)]
			for i in range(n): points[i] = tuple(map(int, stdin.readline().split()))
			S = convexhull(n)
			for _ in range(int(stdin.readline().strip())):
				p = tuple(map(int, stdin.readline().split()))
				if phi(p, S): print("inside")
				else: print("outside")
			stdin.readline().strip()
	except:
		pass

main()