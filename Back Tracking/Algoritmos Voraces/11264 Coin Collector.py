from sys import stdin

coins = None

def phi(n):
	ans, val = 2, coins[0]
	for i in range(1,n-1):
		if val+coins[i] < coins[i+1]: val, ans = val+coins[i], ans+1
	return ans

def main():
	global coins
	T = int(stdin.readline().strip())
	for _ in range(T):
		n = int(stdin.readline().strip())
		coins = list(map(int, stdin.readline().split()))
		print(phi(n))

main()