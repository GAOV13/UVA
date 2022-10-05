from sys import stdin
from math import *

def ecua_cuadratica(a, b, c):
    return (((-1*b) + sqrt(pow(b, 2) - (4*a*c)))/(2*a), (-b - sqrt(pow(b, 2) - (4*a*c)))/(2*a))

def main():
    l, n, c = list(map(float, stdin.readline().split()))
    while l >= 0 and n >= 0 and c >= 0:
        if(l == 0 or n == 0 or c == 0): print("0.000")
        else:
            l_arco = (1 + (n * c)) * l
            r_max = 2147483647.0
            r_min = 0.0
            r = 2147483647.0
            constante = (90*l_arco)/pi
            for i in range(50):
                temp = degrees(asin((l/2)/r))
                if r * temp < constante:
                    r_max = r
                    r = (r_max + r_min)/2
                elif r * temp > constante:
                    r_min = r
                    r = (r_max + r_min)/2
            x1, x2 = ecua_cuadratica(1, (-2*r), (pow(l, 2)/4))
            

            x2 = str(round(x2, 3))
            temp = list(map(str, x2.split(".")))
            print(temp[0] + ".", end="")
            print(temp[1], end="")
            for i in range(3 - len(temp[1])): print("0",end="")
            print()
        l, n, c = list(map(float, stdin.readline().split()))

main()