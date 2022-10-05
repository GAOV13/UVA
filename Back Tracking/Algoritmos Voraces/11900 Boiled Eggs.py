from sys import stdin

eggs = None

def phi(n, P, Q):
	ans, i = 0, 0
	while i < n and P and Q >= eggs[i]:
		i, P, Q, ans = i+1, P-1, Q-eggs[i], ans+1
	return ans

def main():
	global eggs
	case = 0
	T = int(stdin.readline().strip())
	for _ in range(T):
		case += 1
		n, P, Q = list(map(int, stdin.readline().split()))
		eggs = list(map(int, stdin.readline().split()))
		print("Case {}: {}".format(case, phi(n, P, Q)))

main()