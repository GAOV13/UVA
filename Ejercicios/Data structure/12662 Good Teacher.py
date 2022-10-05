from sys import stdin

def main():
    tam = eval(input())
    lista = list(map(str, stdin.readline().split()))
    ini, fin = 0, 0
    
    while lista[ini] == "?": ini += 1
    for i in range(ini): lista[i] = (i - ini, lista[ini])
    for i in range(ini + 1, tam):
        if lista[i] != "?":
            fin = i
            if(ini + 1 != fin):
                medio = (ini + fin) / 2
                if (ini + fin) % 2 == 0: lista[(ini + fin) // 2] = (0, lista[ini], lista[fin])
                for j in range(ini + 1, fin):
                    if j < medio: lista[j] = (j - ini, lista[ini])
                    elif j > medio: lista[j] = (j - fin, lista[fin])
            ini = fin
    for i in range(ini + 1, tam): lista[i] = (i - ini, lista[ini])
    
    m = eval(input())
    while m > 0:
        m -= 1
        indice = eval(input()) - 1
        if type(lista[indice]) == str: print(lista[indice])
        else:
            try:
                num, letra = lista[indice]
                while num != 0:
                    if num > 0:
                        print("right of ", end="")
                        num -= 1
                    else:
                        print("left of ", end="")
                        num += 1
                print(letra)
            except:
                num, letra1, letra2 = lista[indice]
                print("middle of {} and {}".format(letra1, letra2))

main()    