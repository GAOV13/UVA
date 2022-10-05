import numpy as np
import matplotlib
import matplotlib.pyplot as plt

def euler(f, a, b, n, y0):
  h = (b-a)/n
  xx = [a+(i*h) for i in range(n+1)]
  yy = [None for _ in range(n+1)]
  yy[0] = y0
  for i in range(n):
    yy[i+1] = yy[i] + (h*f(xx[i], yy[i]))
  return (xx, yy)

def main():
  df = lambda t, y: 2*t*(y**2)
  f = lambda x: 1/(1-(x**2))
  a, b = 0, 0.9
  n = 40
  y0 = 1
  (xx, yy) = euler(df, a, b, n, y0)
  x = np.linspace(a,b,1000)
  for i in range(n+1):
    print("x:{:.3f}|y:{:.7f}".format(xx[i], yy[i])) 
  plt.plot(xx, yy, "r*")
  plt.plot(x, f(x))
  plt.show()

main()