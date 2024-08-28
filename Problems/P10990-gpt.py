import sys

class Node:
    def __init__(self, d, k, tim):
        self.d = d
        self.k = k
        self.tim = tim

def update(idx, d, k, tim):
    while tot[idx] and nd[idx][-1].d <= d:
        nd[idx].pop()
        tot[idx] -= 1
    nd[idx].append(Node(d, k, tim))
    tot[idx] += 1

def query(u, d, tim):
    for i in range(tot[u] - 1, -1, -1):
        if nd[u][i].tim <= tim:
            if nd[u][i].d >= d:
                return nd[u][i]
    return Node(-1, -1, -1)

def main():
    n, q = map(int, input().split())
    global nd, tot
    nd = [[] for _ in range(n + 1)]
    tot = [0] * (n + 1)

    for i in range(1, n + 1):
        nd[i].append(Node(0, 0, 0))
        tot[i] = 1

    for tim in range(1, q + 1):
        ln = [int(i) for i in input().split()]
        op = ln[0]
        if op == 1:
            u, d, k = ln[1:]
            while u and d >= 0:
                update(u, d, k, tim)
                d -= 1
                u >>= 1
        else:
            u = ln[1]
            t = -1
            res = -1
            d = 0
            while u:
                tt = query(u, d, t)
                if tt.d >= d:
                    t = tt.tim
                    res = tt.k
                d += 1
                u >>= 1
            print(res)

if __name__ == "__main__":
    # sys.stdin = open(f"{name}.in", "r")
    # sys.stdout = open(f"{name}.out", "w")
    main()
