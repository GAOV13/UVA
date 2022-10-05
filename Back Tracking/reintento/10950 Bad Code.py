from sys import stdin

lista = []
conteo = 0

def back(encrypted_str, i, ans, flag):
	global conteo
	if conteo < 100:
		if i == len(encrypted_str):
			if flag: 
				print(ans)
				conteo += 1
		elif encrypted_str[i] == '0': back(encrypted_str, i+1, ans, False)
		else:
			for j in range(26):
				if lista[j] != None:
					if lista[j] == encrypted_str[i:i+len(lista[j])]: back(encrypted_str, i+len(lista[j]), ans + chr(j + 97), True)

def main ():
	global lista, conteo
	N, case, conteo = int(stdin.readline().strip()), 1, 0
	while N:
		lista = [None for _ in range(26)]
		for _ in range(N):
			c, number = list(map(str, stdin.readline().split()))
			lista[ord(c) - 97] = number
		encrypted_str = stdin.readline().strip()
		print("Case #{}".format(case))
		back(encrypted_str, 0, "", True)
		print()
		N, case, conteo = int(stdin.readline().strip()), case+1, 0

main()