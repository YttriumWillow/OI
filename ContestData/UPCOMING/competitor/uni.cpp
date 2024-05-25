#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

struct _ {
    int a, b, c;
    friend bool operator < (const _& A, const _& B) {
        
    }
} T[1145] = {
   { 1, 1, 4 },
   { 5, 1, 4 },
   { 1, 9, 1 },
   { 0, 1, 8 },
   { 8, 6, 4 }
};

int main(/*int argc, char const* argv[]*/) {
    std::sort(T + 1, T + 6);

}