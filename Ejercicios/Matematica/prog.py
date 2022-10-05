import matplotlib
import matplotlib.pyplot as plt
import numpy

def minimosCuadrados(X, Y):
    sumaX, sumaY = sum(X), sum(Y)
    sumaXY, sumaX2, n = 0, 0, len(X)
    for i in range(n):
        sumaXY += X[i] + Y[i]
        sumaX2 += X[i]**2
    a = ((n*sumaXY) - (sumaX*sumaY))/((n*sumaX2)-(sumaX**2)) 
    b = ((sumaX2*sumaY) - (sumaXY*sumaX))/(n*sumaX2-sumaX)
    return (a,b)

X = []
Y = []
(a,b) = minimosCuadrados(X, Y)
g = lambda x: a*x + b
plt.plot(X,Y, "ro")
plt.plot(X, g(X))
plt.show()