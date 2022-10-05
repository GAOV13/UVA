from sys import stdin

prices = None

def phi(n):
	ans = 0
	for i in range(0,n-2, 3): ans += prices[i+2]
	return ans

def main():
	global prices
	t = int(stdin.readline().strip())
	for _ in range(t):
		n = int(stdin.readline().strip())
		prices = sorted(list(map(int, stdin.readline().split())), reverse=True)
		print(phi(n))

main()