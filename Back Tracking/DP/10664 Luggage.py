from sys import stdin

suitCase = []

def luggage(C, W, dic):
	ans = None
	if (C, W) in dic: ans = dic[(C, W)]
	else:
		if C == 0 or W == 0: ans = 0
		elif suitCase[C - 1] > W: ans = luggage(C - 1, W, dic)
		else: ans = max(suitCase[C - 1] + luggage(C - 1, W - suitCase[C - 1], dic), luggage(C - 1, W, dic))
		dic[C, W] = ans
	return ans

def main():
	global suitCase
	m = int(stdin.readline().strip())
	while m:
		suitCase = list(map(int, stdin.readline().split()))
		totalWeight = sum(suitCase)
		if totalWeight % 2 == 1: print("NO")
		else:
			weightToCarry = totalWeight//2
			boat1 = luggage(len(suitCase), weightToCarry, dict())
			if totalWeight - boat1 == boat1: print("YES")
			else: print("NO")
		m -= 1


main()