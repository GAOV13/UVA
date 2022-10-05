from sys import stdin

temp = [(2, 100), (3, 9900), (5, 990000), (7, 0)]

def hallar_precio(cant):
  i = 0
  resp = 0
  while cant > 0:
    mult, limi = temp[i]
    if limi == 0: resp, cant = resp + (cant * mult), 0
    elif cant >= limi: cant, resp = cant - limi, resp + limi * mult
    elif cant < limi: resp, cant = resp + (cant * mult), 0
    i += 1
  return resp

def solve(tsum, diff):
  ans = 0
  val = tsum
  cant, i = 0, 0
  suma = 0
  while not cant:
    mult, limi = temp[i]
    if limi * mult == 0: cant = (val//mult) + suma
    elif limi * mult < val: val, suma = val - (limi*mult), suma + limi
    elif limi * mult == val: cant = limi + suma
    elif limi * mult > val: cant = (val//mult) + suma
    i += 1
  low, hi = 0, cant
  while not ans:
    mid = low + ((hi - low)>>1)
    yo = hallar_precio(mid)
    veci = hallar_precio(cant - mid)
    if veci - yo < diff: hi = mid
    elif veci - yo > diff: low = mid
    else: ans = yo 
  return ans

def main():
  tsum,diff = map(int,stdin.readline().split())
  while tsum+diff!=0:
    print(solve(tsum, diff))
    tsum,diff = map(int,stdin.readline().split())

main()
