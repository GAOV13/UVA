from sys import stdin
from functools import cmp_to_key

p0, points = None, None

def distSq(p1, p2):
	return ((p1[0] - p2[0])**2) + ((p1[1] - p2[1])**2)

def orientation(p1, p2, p3):
	val = (p2[1]-p1[1]) * (p3[0] - p2[0]) - (p2[0] - p1[0]) * (p3[1]-p2[1])
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
	global points, p0
	ymin, min = points[0][1], 0
	for i in range(1, n):
		y = points[i][1]
		if (y < ymin) or (ymin == y and points[min][0] > points[i][0]): ymin, min = points[i][1], i
	points[0], points[min] = points[min], points[0]
	p0, m = points[0], 1
	points.sort(key=cmp_to_key(compare))
	for i in range(1, n):
		while (i < n - 1) and orientation(p0, points[i], points[i+1]) == 0: i+=1
		points[m], m = points[i], m+1
	S = [points[i] for i in range(3)]
	for i in range(3, m):
		while (len(S) > 1) and (orientation(S[-2], S[-1], points[i]) != 2):  S.pop()
		S.append(points[i])
	return S

def main():
	global points
	N = int(stdin.readline().strip())
	print(N)
	while(N):
		N -= 1
		n = int(stdin.readline().strip())
		points = [None for _ in range(n)]
		for i in range(n): points[i] = tuple(map(int, stdin.readline().split()))
		S = convexHull(n)
		print(len(S) + 1)
		for s in S: print("{} {}".format(s[0], s[1]))
		print("{} {}".format(S[0][0], S[0][1]))
		if N: print(stdin.readline().strip())

main()