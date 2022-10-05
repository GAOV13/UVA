from sys import stdin

cabezas, caballeros = None, None

def phi(n, m):
	ans = 0
	if n > m: ans = -1
	else:
		j = 0
		for i in range(n):
			while j < m and cabezas[i] > caballeros[j]: j += 1
			if j == m: 
				ans = -1
				break
			else: ans, j = ans+caballeros[j], j+1
	return ans

def main():
	global cabezas, caballeros
	n, m = list(map(int, stdin.readline().split()))
	while n or m:
		cabezas, caballeros = [None for _ in range(n)], [None for _ in range(m)]
		for i in range(n): cabezas[i] = int(stdin.readline().strip())
		for i in range(m): caballeros[i] = int(stdin.readline().strip())
		cabezas.sort()
		caballeros.sort()
		ans = phi(n,m)
		if ans == -1: print("Loowater is doomed!")
		else: print(ans)
		n, m = list(map(int, stdin.readline().split()))

main()