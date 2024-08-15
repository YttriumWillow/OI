#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

i64 A, B, P;

template<typename T> 
T Mul(T a, T b, T p) {
    T res = 0;
    for (; b; b >>= 1) {
        if (b & 1) res = (res + a) % p;
        a = (a << 1) % p;
    } return res;
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> A >> B >> P;
    std::cout << Mul(A, B, P) << '\n';
}