#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t LL;
typedef double db;
typedef pair <int, int> pin;
 
#ifndef ONLINE_JUDGE
bool MEMORY_ST;
#endif
 
const int N = 49;
const int M = 1 << 23;
const ll P = 998244353LL;
 
int n, p[N], q[N];
LL a, b, c, ca, cb, ans, bin[N][N], fa[M], fb[M];
 
namespace Fread {
    const int L = 1 << 15;
     
    char buffer[L], *S, *T;
     
    inline char Getchar() {
        if(S == T) {
            T = (S = buffer) + fread(buffer, 1, L, stdin);
            if(S == T) return EOF;
        }
        return *S++;
    }
     
    template <class T>
    inline void read(T &X) {
        char ch; T op = 1;
        for(ch = Getchar(); ch > '9' || ch < '0'; ch = Getchar())
            if(ch == '-') op = -1;
        for(X = 0; ch >= '0' && ch <= '9'; ch = Getchar())
            X = (X << 1) + (X << 3) + ch - '0';
        X *= op;
    }
     
} using Fread::read;  
 
namespace Fwrite {
    const int L = 1 << 15;
     
    char buf[L], *pp = buf;
     
    void Putchar(const char c) {
        if(pp - buf == L) fwrite(buf, 1, L, stdout), pp = buf;
        *pp++ = c;
    }
     
    template<typename T>
    void print(T x) {
        if(x < 0) {
            Putchar('-');
            x = -x;
        }
        if(x > 9) print(x / 10);
        Putchar(x % 10 + '0');
    }
     
    void fsh() {
        fwrite(buf, 1, pp - buf, stdout);
        pp = buf;
    }
     
    template <typename T>
    inline void write(T x, char ch = 0) {
        print(x);
        if (ch != 0) Putchar(ch);
        fsh();
    }
 
} using Fwrite::write;
 
#ifndef ONLINE_JUDGE
bool MEMORY_ED;
#endif

void dfs1(int pos, int s, LL cur) {
    if (cur > cb) return;
    if (pos == n + 1) {
        fa[s] = max(fa[s], cur);
        return;
    }
    dfs1(pos + 1, s, cur);
    for (int i = 1; i <= q[pos]; i++) 
        dfs1(pos + 1, s | (1 << (pos - 1)), cur * bin[pos][i]);
}

void dfs2(int pos, int s, LL cur) {
    if (cur > ca) return;
    if (pos == n + 1) {
        fb[s] = max(fb[s], cur);
        return;
    }
    dfs2(pos + 1, s, cur);
    for (int i = 1; i <= q[pos]; i++) 
        dfs2(pos + 1, s | (1 << (pos - 1)), cur * bin[pos][i]);
}

int main() {
    freopen("lcm.in","r",stdin);
    freopen("lcm.out","w",stdout);
 
    srand(time(0));
    read(n);
    c = 1;
    for (int i = 1; i <= n; i++) {
        read(p[i]), read(q[i]);
        bin[i][0] = 1;
        for (int j = 1; j <= q[i]; j++) {
            bin[i][j] = bin[i][j - 1] * p[i];
            c *= p[i];
        }
    }
    read(a), read(b);
    ca = c / a, cb = c / b;
    dfs1(1, 0, 1);
    dfs2(1, 0, 1);
    ans = 2 * c;
    // fa[0] = fb[0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        if (fa[i] == 0) fa[i] = 1;
        if (fb[i] == 0) fb[i] = 1;
    }
    for (int s = 0; s < (1 << n); s++)
        for (int i = 1; i <= n; i++) {
            if (!(s & (1 << (i - 1))))
                fb[s ^ (1 << (i - 1))] = max(fb[s ^ (1 << (i - 1))], fb[s]);
        }
    for (int s1 = 0; s1 < (1 << n); ++s1) {
        int s2 = ((1 << n) - 1) ^ s1;
        ans = min(ans, c / fa[s1] / fb[s2] * (fa[s1] + fb[s2]));
    }
    write(ans - a - b, '\n');
 
    return 0;
}
