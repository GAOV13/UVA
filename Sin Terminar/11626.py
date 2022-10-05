from sys import stdin
from functools import cmp_to_key

p0, points = None, None

def distSq(p1, p2):
	return ((p2[0]-p1[0])**2) + ((p2[1]-p1[1])**2)

def orientation(p, q, r):
	val = (q[1] - p[1]) * (r[0] - q[0]) - (r[1] - q[1]) * (q[0] - p[0])
	if val == 0: return 0
	elif val > 0: return 1
	else: return 2

def compare(p1, p2):
	alpha = orientation(p0, p1, p2)
	if alpha == 0:
		if distSq(p0, p2) >= distSq(p0, p1): return -1
		else: return 1
	else:
		if alpha == 2: return -1
		else: return 1

def convexHull(n):
	global p0, points
	xmin, min = points[0][0], 0
	for i in range(1, n):
		x = points[i][0]
		if (x < xmin) or (x == xmin and points[i][1] < points[min][1]): xmin, min = points[i][0], i
	points[0], points[min] = points[min], points[0]
	p0 = points[0]
	points.sort(key=cmp_to_key(compare))

def main():
	global points
	cases = int(stdin.readline().strip())
	for _ in range(cases):
		n = int(stdin.readline().strip())
		points = []
		for _ in range(n):
			x, y, t = list(map(str, stdin.readline().split()))
			if t == "Y": points.append((int(x), int(y)))
		tam = len(points)
		convexHull(tam)
		print(tam)
		for i in range(tam): print("{} {}".format(points[i][0], points[i][1]))

main()