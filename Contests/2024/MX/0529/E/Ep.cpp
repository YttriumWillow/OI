#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MaxN = 1000000 + 5;
const long long INF = 0x7F7F7F7F7F7F7F7F;

int N;
long long A[MaxN];

struct Trie {
    int cntv;
    std::vector<int> ch[2];

    Trie() { cntv = 1; }

    inline void insert(long long x) {
        int u = 1;
        for (int i = 59; i >= 0; --i) {
            int c = (x & (1LL << i)) ? 1 : 0;
            if (ch[c][u] == 0) ch[c][u] = ++cntv;
            u = ch[c][u];
        }
    }

    inline long long qmin(long long x) {
        long long res = 0; int u = 1;
        for (int i = 59; i >= 0; --i) {
            int c = (x & (1LL << i)) ? 1 : 0;
            if (ch[c][u] != 0) u = ch[c][u];
            else {
                res |= (1LL << i);
                u = ch[c ^ 1][u];
            }
        }
        return res;
    }
};
Trie T;

void init() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);

    T.ch[0].resize(N * 60 + 5);
    T.ch[1].resize(N * 60 + 5);
}

void solve() {
    std::sort(A + 1, A + 1 + N);
    int maxBit = -1;
    for (int i = 59; i >= 0; --i)
        if ((A[1] ^ A[N]) & (1LL << i)) {
            maxBit = i;
            break;
        }

    if (maxBit == -1) {
        printf("%d\n", 0);
        return;
    }

    long long Ans = INF;
    for (int i = 1; i <= N; ++i) {
        if (A[i] & (1LL << maxBit)) Ans = std::min(Ans, T.qmin(A[i]));
        else T.insert(A[i]);
    }
    printf("%lld\n", Ans);
}

int main() {
    //  freopen("b.in", "r", stdin);
    //  freopen("b.out", "w", stdout);
    init();
    solve();
    return 0;
}