from sys import stdin

candidates, info = None, None

def phi(n):
	ans, i = True, 0
	while i < n and ans:
		A, B = candidates[i]
		if A not in info[B]: ans = False
		i += 1
	return ans

def main():
	global candidates, info
	n = int(stdin.readline().strip())
	while n:
		candidates, info = [None for _ in range(n)], dict()
		for i in range(n):
			A, B = list(map(int, stdin.readline().split()))
			if A not in info: info[A] = dict()
			if B not in info: info[B] = dict()
			info[A][B] = True
			candidates[i] = (A, B)
		if n%2 == 0 and phi(n): print("YES")
		else: print("NO")
		n = int(stdin.readline().strip())

main()