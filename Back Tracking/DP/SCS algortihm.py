from sys import stdin

def scs(A, B, i, j):
    """
    SCS con divide y venceras
    """
    ans = None
    if not i or not j: ans = i + j
    elif A[i - 1] == B[j - 1]: ans = 1 + scs(A, B, i-1, j-1)
    else: ans = 1 + min(scs(A, B, i-1, j), scs(A, B, i, j-1))
    return ans

def scsMemo(A, B, i, j, dic):
    """
    SCS con PD usando memorización
    """
    ans = None
    if (i-1,j-1) in dic: ans = dic[(i-1), (j-1)]
    else:
        if not i or not j: ans = i + j
        elif A[i - 1] == B[j - 1]: ans = 1 + scsMemo(A, B, i-1, j-1, dic)
        else: ans = 1 + min(scsMemo(A, B, i-1, j, dic), scsMemo(A, B, i, j-1, dic))
        dic[(i-1,j-1)]= ans
    return ans
    
def scsTab(A, B):
    """
    SCS con PD usando tabulación
    """
    temp = [[None for _ in range(len(B) + 1)] for _ in range(len(A) + 1)]
    for i in range(len(A) + 1): temp[i][0] = i
    for j in range(len(B) + 1): temp[0][j] = j
    for i in range(1, len(A) + 1):
        for j in range(1, len(B) + 1):
            if A[i - 1] == B[j - 1]: temp[i][j] = 1 + temp[i - 1][j - 1]
            else: temp[i][j] = 1 + min(temp[i - 1][j], temp[i][j - 1])
    return temp

def scsStr(A, B, i, j, temp):
    """
    Hallar la cadena de menor tamaño para SCS
    """
    ans = None
    if i == 0: ans = B[0:j]
    elif j == 0: ans = A[0:i]
    elif A[i - 1] == B[j - 1]: ans = scsStr(A, B, i - 1, j - 1, temp) + A[i - 1]
    elif temp[i - 1][j] < temp[i][j - 1]: ans = scsStr(A, B, i - 1, j, temp) + A[i - 1]
    else: ans = scsStr(A, B, i, j - 1, temp) + B[j - 1]
    return ans

def allScsStr(A, B, i, j, temp):
    """
    Hallar todas las cadenas de menor tamaño para SCS
    """
    ans = None
    if i == 0: ans = [B[0:j]]
    elif j == 0: ans = [A[0:i]]
    elif A[i - 1] == B[j - 1]:
        ans = allScsStr(A, B, i-1, j-1, temp)
        for k in range(len(ans)): ans[k] = ans[k] + A[i - 1]
    elif temp[i - 1][j] < temp[i][j - 1]:
        ans = allScsStr(A, B, i-1, j, temp)
        for k in range(len(ans)): ans[k] = ans[k] + A[i - 1]
    elif temp[i - 1][j] > temp[i][j - 1]:
        ans = allScsStr(A, B, i, j-1, temp)
        for k in range(len(ans)): ans[k] = ans[k] + B[j - 1]
    else:
        ans1 = allScsStr(A, B, i-1, j, temp)
        for k in range(len(ans1)): ans1[k] = ans1[k] + A[i - 1]
        ans2 = allScsStr(A, B, i, j-1, temp)
        for k in range(len(ans2)): ans2[k] = ans2[k] + B[j - 1]
        ans = ans1 + ans2
    return ans


def main():
    print("Algortimo para SCS (short common super sequence)")
    A = "ABAAXGF"
    B = "AABXFGA"
    temp = scsTab(A, B)
    print("El scs de {} y {} usando scsTab es = {}".format(A, B, temp[len(A)][len(B)]))
    print("El scs de {} y {} usando scs es = {}".format(A, B, scs(A, B, len(A), len(B))))
    print("El scs de {} y {} usando scsMemo es = {}".format(A, B, scsMemo(A, B, len(A), len(B), dict())))
    print("Uno de los strings que es scs de {} y {} es {} con tam {}".format(A, B, scsStr(A, B, len(A), len(B), temp), temp[len(A)][len(B)]))
    tam = set(allScsStr(A, B, len(A), len(B), temp))
    print("Todas las combinaciones scs de {} y {} son {}".format(A, B, len(tam)))
    print("Y son \n" + str(tam))

main()