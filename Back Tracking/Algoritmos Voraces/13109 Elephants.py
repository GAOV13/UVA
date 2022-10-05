from sys import stdin

elephants = None

def phi(M, W):
	ans, i = 0, 0
	while i < M and elephants[i] <= W: ans, W, i = ans+1, W-elephants[i], i+1
	return ans

def main():
	global elephants
	for _ in range(int(stdin.readline().strip())):
		M, W = list(map(int, stdin.readline().split()))
		elephants = sorted(list(map(int, stdin.readline().split())))
		print(phi(M, W))	

main()