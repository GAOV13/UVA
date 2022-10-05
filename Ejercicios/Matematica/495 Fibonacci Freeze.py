import sys


def fibo(n):
    res = 0
    sig = 1
    for i in range(n):
        suma = res + sig
        res = sig
        sig = suma
    
    return res


for line in sys.stdin:
    n = int(line)
    print("The Fibonacci number for {} is {}".format(n, fibo(n)))
