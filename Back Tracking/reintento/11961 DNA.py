from sys import stdin

tabu = [[1 for _ in range(6)] for _ in range(11)]
acidos = ["A", "C", "G", "T"]

def combi(n, k):
  ans, numerador, denominador = 1, max(k + 1, (n-k)+1), min(k, n-k)
  while numerador <= n: ans, numerador = ans * numerador, numerador + 1
  while denominador > 0: ans, denominador = ans//denominador, denominador - 1
  return ans

def calcular():
  global tabu
  tabu[0][0] = 0
  for i in range(1, 11):
    for j in range(1, 6):
      tabu[i][j] = tabu[i][j-1] + (3**j)*(combi(i, j))
  
def back(K, j, cont, string):
  if j == len(string) or cont == K: print(string)
  else:
    for i in range(4):
      if acidos[i] == string[j]: back(K, j+1, cont, string)
      else:
        ant, string = string[j], string[:j] + acidos[i] + string[j+1:]
        back(K, j+1, cont+1, string)
        string = string[:j] + ant + string[j+1:]

def main():
  calcular()
  T = int(stdin.readline().strip())
  while T:
    T-=1
    N, K = list(map(int, stdin.readline().split()))
    DNA = stdin.readline().strip()
    print(tabu[N][K])
    back(K, 0, 0, DNA)

main()