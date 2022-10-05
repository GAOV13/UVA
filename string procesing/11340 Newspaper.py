from sys import stdin

def main():
  n = int(stdin.readline().strip())
  while n:
    m = int(stdin.readline().strip())
    mapa = {}
    for _ in range(m):
      key, val = list(map(str, stdin.readline().split()))
      mapa[key] = int(val)
    m = int(stdin.readline().strip())
    suma = 0
    for _ in range(m):
      temp = stdin.readline()
      for a in temp:
        val = 0
        try: val = mapa[a]
        except: val = 0
        suma += val
    print("{:.2f}$".format(suma/100))
    n -= 1

main()