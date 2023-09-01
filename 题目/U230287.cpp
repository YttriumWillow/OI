#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
using namespace std;
longint n, T, len, ans;
string line, tmp; bool flag;
int main()
{
    cin >> T;
    getline(cin, tmp);

    while (T--)
    {
        getline(cin, line);

        len = line.size();
        flag = false;
        int i, j;
        for (i = 0; i <= len && line[i] == ' '; i++) {}
        if (line[i] == '#' && line[i + 1] == ' ')
        {
            flag = true;
            for (j = i + 1; j < len && line[j] == ' '; j++) {}
            if (j == len)
                flag = false;
        }
        if (flag)
            ans++;
    }
    cout << ans << endl;
    return 0;
}