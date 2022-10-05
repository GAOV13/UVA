from sys import stdin

teams, tables = None, None
ans = None

def phi(M, N):
	global ans, tables
	flag = True
	for i in range(M):
		cant, j, pos = teams[i][0], 0, teams[i][1]
		while j < N and cant:
			if tables[j][0]:
				ans[pos][len(ans[pos])-cant] = tables[j][1] + 1
				tables[j][0] -= 1
				cant -= 1
			j += 1
		if cant:
			flag = False
			break
		else: tables.sort(key=lambda x: (x[0], x[1]),reverse=True)
	return flag

def main():
	global teams, tables, ans
	M, N = list(map(int, stdin.readline().split()))
	while M or N:
		ans = [None for _ in range(M)]
		teams = list(map(int, stdin.readline().split()))
		for i in range(M): teams[i], ans[i] = (teams[i], i), [None for _ in range(teams[i])]
		tables = list(map(int, stdin.readline().split()))
		for i in range(N): tables[i] = [tables[i], i]
		teams.sort(key=lambda x: (x[0], -x[1]),reverse=True)
		tables.sort(key=lambda x: (x[0], x[1]),reverse=True)
		flag = phi(M, N)
		if flag:
			print(1)
			for l in ans:
				print("{}".format(l[0]), end="")
				for i in range(1, len(l)): print(" {}".format(l[i]), end="")
				print()
		else: print(0)
		M, N = list(map(int, stdin.readline().split()))

main()