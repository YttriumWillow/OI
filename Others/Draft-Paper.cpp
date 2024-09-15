#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

class XHG {
    std::multiset<int, std::greater<int>> S;
public:
    void insert(int v) {
        S.insert(v);
    }
    void remove(int v) {
        auto pos = S.find(v);
        if (pos != S.end()) S.erase(pos);
    }
    int max() {
        return *S.begin();
    }
};

int main(/*int argc, char const* argv[]*/) {
    XHG S;
    S.insert(1);
    S.insert(2);
    S.insert(3);
    S.insert(4);
    std::cout << S.max() << '\n';
}