from sys import stdin

intervalos = None

def phi(M):
	ans = [[], 0, True]
	r = (None, None)
	temp1, temp2 = 0, -1
	for (i,j) in intervalos:
		if i <= temp1 and j > temp2: temp2, r = j, (i, j)
		elif (temp2 >= temp1 and i > temp1):
			temp1, temp2, ans[1] = temp2, -1, ans[1]+1
			ans[0].append(r)
			if temp1 >= M: break
			if i <= temp1 and j > temp2: temp2, r = j, (i, j)
		elif temp2 < temp1 and i > temp1: ans[2] = False
	if temp1 < M and temp2 >= M: 
		ans[0].append(r)
		ans[1] += 1
	elif temp1 < M and temp2 < M: ans[2] = False
	return ans

def main():
	global intervalos
	n = int(stdin.readline().strip())
	while n:
		temp = stdin.readline().strip()
		M = int(stdin.readline().strip())
		intervalos, n = [], n-1
		temp = tuple(map(int, stdin.readline().split()))
		while temp[0] or temp[1]:
			intervalos.append(temp)
			temp = tuple(map(int, stdin.readline().split()))
		intervalos.sort(key=lambda x: (x[0], x[1]))
		ans = phi(M)
		if ans[2]:
			print(ans[1])
			for (i,j) in ans[0]: print("{} {}".format(i, j))
		else: print(0)
		if n: print()

main()