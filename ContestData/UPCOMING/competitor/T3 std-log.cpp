#include <iostream>
#include <queue>
#include <tuple>

#define i64 long long
#define v first
#define id second
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 1.5e5 + 5;

int n, a[N], b[N], c[N]; bool u[N];
std::priority_queue<std::pair<int, int>> A, B, C;

int main() {
    std::cin >> n;
    rep (i, 1, n) {
        std::cin >> a[i] >> b[i] >> c[i];
        A.push({ a[i],i });
        B.push({ b[i],i });
        C.push({ c[i],i });
    }
    while (not A.empty() and not B.empty() and not C.empty()) {
        int x = A.top().id, y = B.top().id, z = C.top().id;
        if (b[x] >= b[y] || c[x] >= c[z]) u[x] = 1;
        if (a[y] >= a[x] || c[y] >= c[z]) u[y] = 1;
        if (a[z] >= a[x] || b[z] >= b[y]) u[z] = 1;
        if (!u[x] and !u[y] and !u[z]) {
            std::cout << a[x] + b[y] + c[z] << '\n';
            return 0;
        }
        while (!A.empty() and u[A.top().id]) A.pop();
        while (!B.empty() and u[B.top().id]) B.pop();
        while (!C.empty() and u[C.top().id]) C.pop();
    }
    std::cout << -1 << '\n';
    return 0;
}