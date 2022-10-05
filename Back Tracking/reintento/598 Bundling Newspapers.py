from sys import stdin

A, ini, fin = None, None, None
res, n = None, None

def phi(m, i, acum):
	global res
	if m >= ini and m <= fin:
		res[m-ini].append(acum)
	
	if m < fin:
		for j in range(i, len(A)):
			phi(m+1,j+1,acum+[A[j]])

def main():
	global A, ini, fin, n, res
	n = int(stdin.readline().strip())
	temp = stdin.readline().strip()
	while n:
		val = list(map(str, stdin.readline().split()))
		A = []
		temp = stdin.readline().strip()
		while temp != "":
			A.append(temp)
			temp = stdin.readline().strip()
		if val[0] == "*": ini, fin = 1, len(A)
		elif len(val) == 1: ini = fin = int(val[0])
		else: ini, fin = int(val[0]), int(val[1])
		res = [[] for _ in range(fin-ini+1)]
		phi(0,0,[])
		for i in range(ini,fin+1):
			print("Size {}".format(i))
			for j in range(0, len(res[i-ini])):
				print(res[i-ini][j][0], end="")
				for k in range(1, len(res[i-ini][j])):
					print(", {}".format(res[i-ini][j][k]), end="")
				print()
			print()
		n -= 1
		if n: print()

main()
