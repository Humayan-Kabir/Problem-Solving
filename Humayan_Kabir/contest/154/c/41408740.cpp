/*
3 3
1 2
2 3
1 3
*/
#include <bits/stdc++.h>
#define mx 1000007
using namespace std;
typedef unsigned long long int ULL;
const ULL base = 1000000007;
ULL h[mx], p[mx];
map<ULL,int> Maping;
int main(int argc, char const *argv[])
{
    p[0] = 1;
    for(int i = 1; i < mx; i++) p[i] = p[i - 1] * base;
    int n, m;
    scanf("%d %d",&n, &m);
    vector< pair<int,int> > edge;
    while(m--)
    {
        int u, v;
        scanf("%d %d",&u, &v);
        u--, v--;
        h[u] += p[v];
        h[v] += p[u];
        edge.push_back(make_pair(u,v));
    }

    long long res = 0;
    for(auto vv : edge)
    {
        int u = vv.first, v = vv.second;
        ULL h1 = h[u] - p[v];
        ULL h2 = h[v] - p[u];
        if(h1 == h2) res++;
    }
    for(int i = 0; i < n; i++) Maping[h[i]]++;
    for(auto v : Maping)
    {
        res += ( 1LL * v.second * (v.second - 1) ) / 2;
    }

    cout << res << endl;
    return 0;
}
