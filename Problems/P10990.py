class Node:
    def __init__(self, d, c, id):
        self.d = d; self.c = c; self.id = id

n, q = map(int, input().split())
v = [[Node(0, 0, 0)] for _ in range(n + 1)]
siz = [1 for _ in range(n + 1)]

def upd(u, d, c, id):
    while siz[u] > 0 and v[u][-1].d <= d:
        v[u].pop(); siz[u] -= 1
    v[u].append(Node(d, c, id)); siz[u] += 1

def request(u, d, id):
    i = siz[u] - 1
    while v[u][i].id > id and id >= 0:
        if v[u][i].d >= d: return v[u][i]
        i -= 1
    return Node(-1,-1,-1)


for id in range(1, q + 1):
    ln = [int(i) for i in input().split()]
    if ln[0] == 1:
        o, u, d, c = ln
        while u > 0 and d >= 0:
            upd(u, d, c, id)
            d -= 1; u >>= 1
    else:
        o, u = ln
        id, res, d = -1, -1, 0
        while u > 0:
            T = request(u, d, id)
            if T.id >= id: id, res = T.id, T.c 
            d += 1; u >>= 1;
        print(res)