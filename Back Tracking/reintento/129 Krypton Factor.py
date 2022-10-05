from sys import stdin
from math import ceil

acum, ans = None, None

def verificar(A):
  j, tam = 1, len(A)
  flag = True
  while j <= tam//2 and flag:
    if A[tam-j:tam] == A[tam-(2*j):tam-j]: flag = False
    j+=1
  return flag

def crear(n, L, temp):
  global acum, ans
  if acum <= n:
    for i in range(L):
      if acum >= n: break
      if verificar(temp+chr(65+i)):
        acum += 1
        crear(n, L, temp+chr(65+i))
  if acum == n: ans, acum = temp, acum+1

def main():
  global acum, ans
  n, L = list(map(int, stdin.readline().split()))
  while n + L:
    acum, ans = 0, ""
    crear(n, L, "")
    print(ans[:4], end="")
    i = 1
    while i < ceil(len(ans)/4):
      if i == 16: print("\n{}".format(ans[i*4: (i+1)*4]), end="")
      else: print(" {}".format(ans[i*4: (i+1)*4]), end="")
      i += 1
    print()
    print(len(ans))
    n, L = list(map(int, stdin.readline().split()))

main()