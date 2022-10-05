from sys import stdin

lista = []

def aprox(num, dig):
    num = num * (10**dig)
    num += 0.5
    num = num//1
    return num/(10**dig)

def back(suma, i, j, N, M, cant, horas, dic):
    ans = None
    k = i*M+j
    if (k, cant, horas, suma) in dic: ans = dic[(k, cant, horas, suma)]
    else:
        if cant == N and horas <= M: ans = suma
        elif cant == N and horas > M: ans = 0
        elif i >= N: ans = 0
        elif horas + j + 1 > M: ans = 0
        elif lista[k] < 5: ans = back(suma, i, j + 1, N, M, cant, horas, dic)
        else: ans = max(back(suma, i, j + 1, N, M, cant, horas, dic), back(suma + lista[k], i + 1, 0, N, M, cant + 1, horas + j + 1, dic))
        dic[(k, cant, horas, suma)] = ans
    return ans

def main():
    global lista
    T = int(stdin.readline().strip())
    while T:
        lista = []
        N, M = map(int, stdin.readline().split())
        for _ in range(N):  lista += list(map(int, stdin.readline().split()))
        num = back(0, 0, 0, N, M, 0, 0, dict())/N
        if num:
            print("Maximal possible average mark -", end =" ")
            print("{:.2f}.".format(aprox(num, 2)))
        else: print("Peter, you shouldn't have played billiard that much.")
        T -= 1


main()