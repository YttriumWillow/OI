#include <iostream>
#include <algorithm>
#include <tuple>

#define i64 long long
#define v first
#define id second
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 1.5e5 + 5;

int n; bool u[N];
int a[N], b[N], c[N];

struct Pii {
    int v, id;
    friend bool operator < (const Pii& X, const Pii& Y) {
        return (X.v != Y.v) ? (X.v > Y.v) : (X.id < Y.id);
    }
} A[N], B[N], C[N];

int main() {
    std::cin >> n;
    rep (i, 1, n) {
        std::cin >> a[i] >> b[i] >> c[i];
        A[i] = { a[i], i };
        B[i] = { b[i], i };
        C[i] = { c[i], i };
    }

    std::sort(A + 1, A + n + 1);
    std::sort(B + 1, B + n + 1);
    std::sort(C + 1, C + n + 1);
    int pA = 1, pB = 1, pC = 1;

    while (pa <= n and pb <= n and pc <= n) {
        int x = A.top().id, y = B.top().id, z = C.top().id;

        int x = A[pA].id, y = B[pB].id;, z = C[pC].id; 
        if (b[x] == b[y] || c[x] == c[z]) u[x] = 1;
        if (a[y] == a[x] || c[y] == c[z]) u[y] = 1;
        if (a[z] == a[x] || b[z] == b[y]) u[z] = 1;
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