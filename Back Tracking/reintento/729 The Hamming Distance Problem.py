from sys import stdin

def back(j, cont, H, string):
  if cont == H: print(string)
  elif cont < H:
    for i in range(j, len(string)):
      string = string[:i] + "0" + string[i+1:]
      back(i+1, cont+1, H, string)
      string = string[:i] + "1" + string[i+1:]

def main():
  M = int(stdin.readline().strip())
  while M:
    M -= 1
    stdin.readline()
    N, H = list(map(int, stdin.readline().split()))
    cambios = N-H
    back(0, 0, cambios, "1"*N)
    if M: print()

main()