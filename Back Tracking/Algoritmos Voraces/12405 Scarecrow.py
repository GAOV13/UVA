from sys import stdin

ruta = None

def phi(n):
	ans, i = 0, 1
	while i <= n:
		if ruta[i-1] == '.': ans, i = ans+1, i+3
		else: i+=1
	return ans

def main():
	global ruta
	T = int(stdin.readline().strip())
	for i in range(T):
		n = int(stdin.readline().strip())
		ruta = stdin.readline().strip()
		print("Case {}: {}".format(i+1, phi(n)))

main()