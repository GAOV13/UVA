from sys import stdin

size, ans = None, None

def back(n, res):
  global ans, size
  if len(res) < size:
    if res[-1] == n: ans, size = res.copy(), len(res)
    elif res[-1] < n:
      i = len(res) - 1
      while i >= 0 and res[i] + res[i] > res[-1]:
        j = i
        while j >= 0 and res[i] + res[j] > res[-1]:
          back(n, res + [res[i] + res[j]])
          j-=1
        i-=1

def main():
  global size, ans
  n, size, ans = int(stdin.readline().strip()), 2**32, []
  while n:
    back(n, [1])
    print(1, end="")
    for i in range(1, size): print(" " + str(ans[i]), end="")
    print()
    n, size, ans = int(stdin.readline().strip()), 2**32, []


main()