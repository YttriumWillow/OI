#include <iostream>
#include <stack>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 1e5 + 10;

int n, x[N], res[N];
int p, pos[N];
char c[N];
std::stack<int> st;

int main(/*int argc, char const* argv[]*/) {
    file("c");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) { std::cin >> x[i]; }
    rep (i, 1, n) { std::cin >> c[i]; }
    rep (i, 1, n) { res[i] = -1; }

    rep (i, 1, n) {
        if (c[i] == 'R') {
            st.push(i);
        }
        if (c[i] == 'L') {
            if (st.empty()) { continue; }
            else {
                int q = st.top(); st.pop();
                res[q] = res[i] = x[i] - x[q];
            }
        }
    }

    rep (i, 1, n) {
        std::cout << res[i] << ' ';
    }

}