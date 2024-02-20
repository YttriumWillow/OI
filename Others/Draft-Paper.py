from math import *

W = int(input())

if W <= 50:
	F = 1.3 * W
else:
	F = 1.3 * 50 + 1.8 * (W - 50)

print(F)