from sys import stdin

ans = None
constraints = []

def back(sits, vis, n):
  global ans
  if n == len(sits): ans += 1
  for i in range(len(sits)):
    if sits[i] == None:
      flag, j = True, 0,
      while j < n and flag:
        if len(constraints[j][n]):
          for k in constraints[j][n]:
            val = abs(vis[j] - i)
            if k > 0 and k < val: flag = False
            elif k < 0 and (k * -1) > val: flag = False
            if not flag: break
        j += 1
      if flag:
        sits[i], vis[n] = n, i
        back(sits, vis, n+1)
        sits[i], vis[n] = None, -1

def main():
  global ans, constraints
  n, m = list(map(int, stdin.readline().split()))
  while n or m:
    constraints = [[[] for _ in range(n)] for _ in range(n)]
    for _ in range(m):
      a,b,c = list(map(int, stdin.readline().split()))
      constraints[a][b] = constraints[b][a] = constraints[b][a] + [c]
    sits, vis, ans = [None for _ in range(n)], [-1 for _ in range(n)], 0
    back(sits, vis, 0)
    print(ans)
    n, m = list(map(int, stdin.readline().split()))
  
main()