from sys import stdin

intervalos = None

def phi(M):
	ans, temp1, temp2 = 0, 0, -1
	for (i,j) in intervalos:
		if i <= temp1 and j > temp2: temp2= j
		elif (temp2 >= temp1 and i > temp1):
			temp1, temp2, ans = temp2, -1, ans+1
			if temp1 >= M: break
			if i <= temp1 and j > temp2: temp2 = j
		elif temp2 < temp1 and i > temp1: 
			ans = -1
			break
	if temp1 < M and temp2 >= M: ans += 1
	elif temp1 < M and temp2 < M: ans = -1
	return ans

def main():
	global intervalos
	temp = stdin.readline().strip()
	while temp != "":
		n, l, w = list(map(int, temp.split()))
		intervalos = [None for _ in  range(n)]
		for i in range(n):
			pos, r = list(map(int, stdin.readline().split()))
			x = (r**2 - (w/2)**2)
			if x >= 0: x = x**(1/2)
			else: x = 0
			intervalos[i] = (pos-x, pos+x)
		intervalos.sort(key=lambda x: (x[0], x[1]))
		print(phi(l))
		temp = stdin.readline().strip()

main()