from math import floor, sqrt
from sys import stdin

def lowerS(lista, num, low, hi):
    mid = (low + hi)>> 1
    if(mid == low):
        if(lista[mid] == num):
            return mid; 

        else:
            return mid + 1
    
    if(lista[mid] < num): 
        return lowerS(lista, num, mid, hi)

    else: 
        return lowerS(lista, num, low, mid)


def upperS(lista, num, low, hi):
    mid = (low + hi) >> 1
    if(low == mid):
        return hi
    
    if(lista[mid] <= num):
        return upperS(lista, num, mid, hi)
    
    else:
        return upperS(lista, num, low, mid)


def NOD(num):
    suma = 0
    tam = floor(sqrt(num))
    for i in range(1, tam + 1):
        if(num % i == 0):
            suma += 1
                
            if(floor(num/i) != i):
                suma += 1
    return suma


def main():
    n = eval(input())
    casos = 1
    lista = [1]
    while(n > 0):
        min, max = list(map(int, stdin.readline().split()))
        while(lista[len(lista) - 1] <= 1000000 and lista[len(lista) - 1] <= max):
            k = NOD(lista[len(lista) - 1])
            k += lista[len(lista) - 1]
            lista.append(k)

        ini = lowerS(lista, min, 0, len(lista))
        fin = upperS(lista, max, ini, len(lista))
        print("Case {}: {}".format(casos, fin - ini))
        casos += 1
        n -= 1


main()