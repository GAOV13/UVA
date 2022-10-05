from sys import stdin
from math import floor, log2

def buscar(L, U):
  i = 0
  while i < len(L) and L[i] == U[i]: i+=1
  return i

def minMask(N, L, U):
  j = buscar(L, U)
  M = L[:j+1] + ("0"*(len(N)-(j+1)))
  ver = True
  for i in range(j, len(N)):
    if(ver):
      if N[i] == '1': M = M[:i] + L[i] + M[i+1:]
      else: M = M[:i] + "1" + M[i+1:]
      if int(M,2) >= int(L,2): ver = False
    elif M[i] == N[i] and N[i] == "0":
      temp = M[:i] + "1" + M[i+1:]
      if int(U,2) >= int(temp, 2): M = temp
  return int(M,2)

def main():
  try:
    for temp in stdin:
      N, L, U = list(map(int, temp.split()))
      cant_dig = 0
      if N: cant_dig = max(floor(log2(N)), cant_dig)
      if L: cant_dig = max(floor(log2(L)), cant_dig)
      if U: cant_dig = max(floor(log2(U)), cant_dig)
      cant_dig += 1
      N, L, U, = bin(N)[2:].zfill(cant_dig), bin(L)[2:].zfill(cant_dig), bin(U)[2:].zfill(cant_dig)
      print(minMask(N, L, U))
  except:
    return 0

main()