from sys import stdin

grafo, visitados, ans, case = {}, [], 0, 0

def back(u, fin, acum):
  global visitados, ans
  if u == fin:
    print(acum)
    ans += 1
  else:
    for v in grafo[u]:
      if not visitados[v]:
        visitados[v] = 1
        back(v, fin, acum + " " + str(v))
        visitados[v] = 0

def dfs(fin, ini):
  global visitados
  visitados[ini] = 0
  if ini != fin:
    for u in grafo[ini]:
      if visitados[u]: dfs(fin, u)

def main():
  global grafo, visitados, ans, case
  try:
    for N in stdin:
      grafo, visitados, ans, case = [[] for _ in range(int(N) + 1)], [-1 for _ in range(int(N) + 1)], 0, case+1
      ini, fin = list(map(int, stdin.readline().split()))
      tam = int(N)
      while ini + fin:
        if ini >= tam or fin >= tam: tam = max(tam, ini+1, fin+1)
        while len(grafo) < tam: 
          grafo.append([])
          visitados.append(-1)
        grafo[ini].append(fin)
        grafo[fin].append(ini)
        ini, fin = list(map(int, stdin.readline().split()))
      for i in range(1, len(grafo)): grafo[i].sort()
      dfs(1, int(N))
      visitados[1] = 1
      print("CASE {}:".format(case))
      back(1, int(N), str(1))
      print("There are {} routes from the firestation to streetcorner {}.".format(ans, int(N)))
  except:
    return 0

main()