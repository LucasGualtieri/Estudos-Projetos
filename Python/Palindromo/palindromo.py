import sys

def isPalindromo(x):
	for i in range(0, (int)(len(x) / 2), 1):
		if (x[i] !=  x[len(x) - i - 1]): return False
	return True

def main():

	sys.stdin = open('pub.in', 'r')
	sys.stdout = open('result.txt', 'w')

	inputStr = input()
	while inputStr != "FIM":
		print("SIM" if isPalindromo(inputStr) else "NAO")
		inputStr = input()

main()