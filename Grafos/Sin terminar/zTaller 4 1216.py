from sys import stdin
from queue import PriorityQueue
from math import ceil, sqrt

aristas = []
sensores = []
mst = []
info = []
dic = {}

class Arista():
    def __init__(self, x1, y1, x2, y2, u, v):
        self.u = u
        self.v = v
        self.nodo1 = (x1, y1)
        self.nodo2 = (x2, y2)


def kruskal(tam, m):
    global aristas, sensores, mst, info, dic
    for i in range(tam):
        sensores[i] = i

    if tam <= m:
        return
    
    aristas.sort()
    for temp in aristas:
        peso, ide = temp
        u = info[ide].u
        v = info[ide].v
        if sensores[u] != sensores[v]:
            mst.append((peso, ide))
            p1 = sensores[u]
            p2 = sensores[v]
            dic = {}
            for i in range(tam):
                if sensores[i] == p2:
                    sensores[i] = p1
                    dic[p1] = [0]
                else:
                    dic[sensores[i]] = [0]
            
            if len(dic) == m:
                for (peso, u) in mst:
                    u = info[u].u
                    dic[sensores[u]][0] += 1
                    dic[sensores[u]].append(peso)
                return
    
    dic = {}


def main():
    global aristas, sensores, mst, info, dic
    n = eval(input())
    while n != 0:
        peso = []
        sensores = []
        info = []
        mst = []
        m = eval(input())
        temp = list(map(int, stdin.readline().split()))
        i = 0
        while len(temp) == 2:
            sensores.append((temp[0], temp[1]))
            temp = list(map(int, stdin.readline().split()))
            i += 1

        tam = i
        index = 0
        for i in range(len(sensores) - 1):
            for j in range(1, len(sensores)):
                x1, y1 = sensores[i]
                x2, y2 = sensores[j]
                peso = sqrt(pow(x2 -  x1, 2) + pow(y2 - y1, 2))
                aristas.append((peso, index))
                info.append(Arista(x1, y1, x2, y2, i, j))
                index += 1
        
        kruskal(tam, m)
        d = 0
        if len(dic) > 0:
            tam = 0
            for v in dic:
                print("{}: ".format(v), end="")
                print(dic[v])
        n -= 1


main()