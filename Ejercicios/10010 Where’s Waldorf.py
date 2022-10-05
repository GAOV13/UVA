from sys import stdin

moveX = [0, 1, 1, 1, 0, -1, -1, -1]
moveY = [1, 1, 0, -1, -1, -1, 0, 1]
grid = None

def validar(y, x, l, fil, col):
	ans = False
	if y + moveY[l] >= 0 and y + moveY[l] < fil and x + moveX[l] >= 0 and x + moveX[l] < col: ans = True
	return ans

def busqueda(fil, col, temp):
	for i in range(fil):
		for j in range(col):
			if temp[0] == grid[i][j]:
				for l in range(8):
					y, x = i, j
					k = 1
					while k < len(temp) and validar(y, x, l, fil, col):
						y, x = y+moveY[l], x+moveX[l]
						if grid[y][x] == temp[k]: k += 1
						else: break 
					if k == len(temp): return i+1, j+1

def main():
	global grid
	n = int(stdin.readline().strip())
	while n:
		temp = stdin.readline().strip()
		fil, col = list(map(int, stdin.readline().split()))
		grid = [None for _ in range(fil)]
		for i in range(fil): grid[i] = stdin.readline().strip().lower()
		cases = int(stdin.readline().strip())
		for _ in range(cases):
			temp = stdin.readline().strip().lower()
			i, j = busqueda(fil, col, temp)
			print("{} {}".format(i, j))
		n -= 1
		if n: print()

main()