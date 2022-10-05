from sys import stdin

ans, res, case = 2**32, 0, 0

def sort(A, acum, flag):
  global ans, res
  if acum <= ans:
    for i in range(len(A) - 1):
      if A[i] > A[i+1]:
        temp1, temp2, flag = A[i], A[i+1], False
        A[i], A[i+1] = temp2, temp1
        sort(A, acum+1, True)
        A[i], A[i+1] = temp1, temp2
    if flag and acum == ans: res += 1
    elif flag and acum < ans: ans, res = acum, 1

def main():
  global ans, res, case
  A = list(map(int, stdin.readline().split()))
  while A[0]:
    n, A, ans, res, case = A[0], A[1:], 2**32, 0, case + 1
    sort(A, 0, False)
    print("There are {} swap maps for input data set {}.".format(res, case))
    A = list(map(int, stdin.readline().split()))

main()