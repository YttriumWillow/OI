#include<bits/stdc++.h>
using namespace std;
int findSample(int n, int* confidence, int* host, int* opt)
{
    host[0] = 0;
    while (--n)
        if (!opt[n])
            host[0] += confidence[n], confidence[host[n]] = max(0, confidence[host[n]] - confidence[n]);
        else if (opt[n] == 1)
            confidence[host[n]] += confidence[n];
        else
            confidence[host[n]] = max(confidence[host[n]], confidence[n]);
    return host[0] + confidence[0];
}
