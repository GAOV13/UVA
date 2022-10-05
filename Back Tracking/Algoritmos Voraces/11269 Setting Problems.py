from sys import stdin

def main():
  try:
    for temp in stdin:
      N, casesP, casesN, ans, acum = int(temp), [], [], 0, 0
      S = list(map(int, stdin.readline().split()))
      G = list(map(int, stdin.readline().split()))
      for i in range(N):
        if G[i]-S[i] < 0: casesN.append((S[i], G[i]))
        else: casesP.append((S[i], G[i]))
      cases = sorted(casesP) + sorted(casesN, reverse=True, key=lambda x: x[1])
      for (S, G) in cases: ans, acum = max(acum + S + G, ans + G), acum + S
      print(ans)
  except:
    return 0

main()