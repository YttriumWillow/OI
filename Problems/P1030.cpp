#include <iostream>

#include <cstring>

#define longmidt long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string midord, suford;

void fzyqwq(string mid, string suf)
{
    if (!mid.empty())
    {
        cout << suf[suf.size() - 1];
        int k = mid.find(suf[suf.size() - 1]);
        fzyqwq(mid.substr(0, k), suf.substr(0, k));
        fzyqwq(mid.substr(k + 1), suf.substr(k, mid.size() - k - 1));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> midord;
    cin >> suford;
    fzyqwq(midord, suford);
    cout << endl;
    return 0;
}