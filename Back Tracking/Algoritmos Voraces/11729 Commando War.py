from sys import stdin

def main():
  N, case, casos, ans, acum = int(stdin.readline().strip()), 1, [], 0, 0
  while N:
    for i in range(N): casos.append(tuple(map(int, stdin.readline().split())))
    casos.sort(reverse=True, key=lambda x: x[1])
    for (B, J) in casos: ans, acum = max(acum + J + B, ans), acum + B
    print("Case {}: {}".format(case, ans))
    N, case, casos, ans, acum = int(stdin.readline().strip()), case+1, [], 0, 0

main()