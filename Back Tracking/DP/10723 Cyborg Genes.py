#idea de como hallar un scs sacada de https://www.geeksforgeeks.org/shortest-possible-combination-two-strings/

from sys import stdin
    
def scsTab(A, B):
    temp = [[None for _ in range(len(B) + 1)] for _ in range(len(A) + 1)]
    for i in range(0, len(A) + 1):
        for j in range(0, len(B) + 1):
            if j == 0: temp[i][0] = i
            elif i == 0: temp[0][j] = j
            elif A[i - 1] == B[j - 1]: temp[i][j] = 1 + temp[i - 1][j - 1]
            else: temp[i][j] = 1 + min(temp[i - 1][j], temp[i][j - 1])
    return temp


def allScsStr(A, B, i, j, temp, dic):
    ans = None
    if (i-1, j-1) in dic: ans = dic[(i-1,j-1)]
    else:
        if not i or not j: ans = 1
        elif A[i - 1] == B[j - 1]: ans = allScsStr(A, B, i-1, j-1, temp, dic)
        elif temp[i - 1][j] < temp[i][j - 1]: ans = allScsStr(A, B, i-1, j, temp, dic)
        elif temp[i - 1][j] > temp[i][j - 1]: ans = allScsStr(A, B, i, j-1, temp, dic)
        else: ans = allScsStr(A, B, i-1, j, temp, dic) + allScsStr(A, B, i, j-1, temp, dic)
        dic[(i-1,j-1)] = ans
    return ans


def main():
    casos = 1
    n = int(stdin.readline().strip())
    while n:
        print("Case #{}:".format(casos), end=" ")
        casos += 1
        A = stdin.readline().strip()
        B = stdin.readline().strip()
        temp = scsTab(A, B)
        print(temp[len(A)][len(B)], end=" ")
        lisa = allScsStr(A, B, len(A), len(B), temp, dict())
        print(lisa)
        n -= 1

main()