import sys

sys.stdin  = open("number.in","r")
sys.stdout = open("number.out","w")

a, b = map(int, input().split())
d = max(a - b, b - a)
if (d == 0): 
    print("Forever")
    exit(0)
res = 3
while d % 2 == 0:
    d = d // 2
    res += 1
print(res)
