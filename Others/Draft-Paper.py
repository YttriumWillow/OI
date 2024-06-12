n = 13
t = [[0] * n for _ in range(n)]

for i in range(n):
    t[i][0] = 1

for i in range(1, n):
    for j in range(1, n):
        t[i][j] = t[i - 1][j - 1] + t[i - 1][j]

for i in range(n):
    for j in range(n - i - 1):
        print ("  ", end = "")
    for j in range(i + 1):
        print ("%-4d" % t[i][j], end="")
    print()