from sys import stdin

def main():
  try:
    for temp in stdin:
      puntos, lista = 0, []
      N, G = list(map(int, temp.split()))
      for i in range(N):
        S, R = list(map(int,stdin.readline().split()))
        if R - S < 0: puntos += 3
        else: lista.append(R - S)
      lista.sort()
      for num in lista:
        if G > num: puntos, G = puntos + 3, G - num - 1
        elif G == num: puntos, G = puntos + 1, -1
        elif not num: puntos += 1
        else: break
      print(puntos)
  except:
    return 0

main() 