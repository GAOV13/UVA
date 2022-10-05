from sys import stdin

intervalos = None

def phi():
	ans, k = 1, intervalos[0][1]
	for (i,j) in intervalos:
		if i > k: k, ans = j, ans+1
	return ans

def main():
	global intervalos
	n, r = list(map(int, stdin.readline().split()))
	caso = 0
	while n+r:
		caso += 1
		ver = True
		intervalos = [None for _ in range(n)]
		for i in range(n):
			x, y = list(map(int, stdin.readline().split()))
			dx = (r**2 - y**2)
			if dx < 0: ver = False
			else: dx = dx**(1/2)
			intervalos[i] = (x-dx, x+dx)
		print("Case {}: ".format(caso), end="")
		if ver:
			intervalos.sort(key=lambda x: (x[1], x[0]))
			print(phi())
		else: print(-1)
		stdin.readline()
		n, r = list(map(int, stdin.readline().split()))

main()