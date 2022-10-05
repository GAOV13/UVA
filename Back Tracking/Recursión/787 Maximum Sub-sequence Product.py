from sys import stdin

lista = None

def crossArray(low, mid, hi):
  leftPRpos, rightPRpos , suma = 0, 0, 1
  leftPRneg, rightPRneg = 0, 0
  i = mid
  while i >= low:
    suma *= lista[i]
    leftPRpos, leftPRneg = max(suma, leftPRpos), min(suma, leftPRneg)
    i-=1
  suma = 1
  for i in range(mid+1,hi+1):
    suma *= lista[i]
    rightPRpos, rightPRneg = max(suma, rightPRpos), min(rightPRneg, suma)
  return max(leftPRpos*rightPRpos, leftPRneg*rightPRneg, leftPRpos, rightPRpos)

def rangeProd(low, hi):
  ans = None
  if low == hi: ans = lista[low]
  else:
    mid = (low+hi)//2
    ans = max(rangeProd(low, mid), rangeProd(mid+1, hi), crossArray(low, mid, hi))
  return ans

def main():
  global lista
  linea = stdin.readline().strip()
  while linea != "":
    lista = list(map(int, linea.split()))[:-1]
    print(rangeProd(0, len(lista) - 1))
    linea = stdin.readline().strip()

main()