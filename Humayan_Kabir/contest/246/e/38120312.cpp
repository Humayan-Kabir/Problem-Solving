#include<bits/stdc++.h>
#define mx 200007
using namespace std;
map<string,int> Maping;
map<int,int> cnt[mx];
vector<int> graph[mx];
vector< pair<int,int> > Query[mx];
int sz[mx], st[mx], ft[mx], ver[mx], height[mx], ans[mx], color[mx], distinct[mx], Timer = 0;
void getSz(int u,int par)
{
    st[u] = ++Timer;
    ver[Timer] = u;
    sz[u] = 1;
    par == -1 ? height[u] = 0 : height[u] = height[par] + 1;
    for(int v : graph[u])
        if(v != par)
           getSz(v,u), sz[u] += sz[v];
    ft[u] = Timer;
}
inline void add(int Time)
{
    int v = ver[Time], h = height[v],col = color[v];
    cnt[h][col]++;
    if(cnt[h][col] == 1) distinct[h]++;
}
inline void remov(int Time)
{
    int v = ver[Time], h = height[v],col = color[v];
    cnt[h][col]--;
    if(cnt[h][col] == 0) distinct[h]--;
}
void dfs(int u,int par,int keep)
{
    int MX = -1, bigChild = -1;

    for(int v : graph[u])
        if(v != par && sz[v] > MX)
           MX = sz[v], bigChild = v;

    for(int v : graph[u])
        if(v != par && v != bigChild)
            dfs(v,u,0);

    if(bigChild != -1) dfs(bigChild,u,1);

    for(int v : graph[u])
        if(v != par && v != bigChild)
        for(int i = st[v]; i<=ft[v]; i++)
           add(i);

    add(st[u]);

    for(auto qq : Query[u])
       ans[qq.second] = distinct[qq.first];

    if(keep == 0)
    {
        for(int i = st[u]; i<=ft[u]; i++)
            remov(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n, root = 0;
    cin >> n;
    for(int i = 1, id = 0; i<=n; i++)
    {
        string str; int p;
        cin >> str >> p;
        if(Maping.find(str) == Maping.end())
        {
            Maping[str] = ++id;;
        }
        color[i] = Maping[str];
        graph[p].push_back(i);
    }
    getSz(root, -1);
    int q;
    cin >> q;
    for(int i = 1; i<=q; i++)
    {
        int v, k;
        cin >> v >> k;
        Query[v].push_back({height[v] + k , i});
    }
    dfs(root,-1,0);
    for(int i = 1; i<=q; i++) cout << ans[i] << endl;
    return 0;
}
