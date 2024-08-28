n, m = map(int, input().split())
tag = [[0] * 21 for _ in range(n + 1)]
tim = [[0] * 21 for _ in range(n + 1)]

for i in range(1, m + 1):
    ln = [int(i) for i in input().split()]
    op = ln[0]
    if op == 1:
        x, y, z = ln[1:]
        while x and y >= 0:
            tag[x][min(y, 20)] = z
            tim[x][min(y, 20)] = i
            x >>= 1; y -= 1
    else:
        x = ln[1]
        y = 0; t = 0; res = 0
        while x:
            for j in range(y, 21):
                if tim[x][j] > t:
                    t = tim[x][j]
                    res = tag[x][j]
            x >>= 1; y += 1
        print(res)
