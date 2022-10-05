from sys import stdin

ruta, dire = "IEHOVA#", [(-1, 0), (0, -1), (0, 1)] 
flag, grafo = None, None

def dfs(i, j, k):
  global flag
  if k == 7: flag = False
  else:
    n = 0
    while flag and n < 3:
      fil, col = i + dire[n][0], j + dire[n][1]
      if fil >= 0 and fil < len(grafo) and col >= 0 and col < len(grafo[i]):
        if grafo[fil][col] == ruta[k]:
          if k: print(" ", end="")
          if n == 0: print("forth", end="")
          elif n == 1: print("left", end="")
          elif n == 2: print("right", end="")
          dfs(fil, col, k+1)
      n+=1

def main():
  global grafo, flag
  C = int(stdin.readline().strip())
  while C:
    m, n = list(map(int, stdin.readline().split()))
    grafo, C, start, flag = [[None for _ in range(n)] for _ in range(m)], C-1, None, True
    for i in range(m):
      temp = stdin.readline().strip()
      for j in range(n):
        grafo[i][j] = temp[j]
        if temp[j] == "@": start = (i, j)
    dfs(start[0], start[1], 0)
    print()

main()