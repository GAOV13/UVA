from sys import stdin

dia, noche = None, None

def phi(n, d, r):
	ans = 0
	for i in range(n):
		t = dia[i]+noche[i]-d 
		if t > 0: ans += t*r
	return ans

def main():
	global dia, noche
	n, d, r = list(map(int, stdin.readline().split()))
	while n or d or r:
			dia = list(map(int, stdin.readline().split()))
			noche = list(map(int, stdin.readline().split()))
			dia.sort()
			noche.sort(reverse=True)
			print(phi(n,d,r))
			n, d, r = list(map(int, stdin.readline().split()))

main()