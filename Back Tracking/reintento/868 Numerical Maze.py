from sys import stdin

dire, flag, mini, maze = [(0, -1), (1, 0), (-1, 0) ,(0, 1)], None, None, None

def busc(i, j, num, lim):
  global maze, flag, mini
  if i == len(maze) - 1: flag, mini = False, min(mini, j+1)
  else:
    for k in range(4):
      fil, col = i + dire[k][0], j + dire[k][1]
      if fil >= 0 and fil < len(maze) and col >= 0 and col < len(maze[0]):
        if(num == maze[fil][col]):
          temp, maze[i][j] = maze[i][j], None
          if lim == num: busc(fil, col, 1, lim+1)
          else: busc(fil, col, num+1, lim)
          maze[i][j] = temp

def buscar(N, M):
  global flag, mini
  mini, flag, i = 2**32, True, 0
  while i < M and flag:
    if maze[0][i] == 1: busc(0,i,1,2)
    i+=1
  return (i,mini)

def main():
  global maze
  K = int(stdin.readline().strip())
  while K:
    stdin.readline().strip()
    K-=1
    N, M = list(map(int, stdin.readline().split()))
    maze = [None for _ in range(N)]
    for i in range(N): maze[i] = list(map(int, stdin.readline().split()))
    val = buscar(N, M)
    print("{} {}\n{} {}".format(1, val[0], N, val[1]))
    if K: print()

main()