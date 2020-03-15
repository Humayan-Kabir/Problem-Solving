/*Template from Sakibul Moula Vai*/
#include <bits/stdc++.h>
using namespace std;

struct CentroidTree
{
    vector < vector<int> > graph;
    vector < vector<int> > lcapar;
    vector <int> ctpar, subtree, level;
    vector <bool> IsDeleted;
    const int inf = 1E9;
    int n;
    int Root = 0;
    int LogN = 20;
    CentroidTree(int n): n(n), graph(n), ctpar(n), subtree(n), level(n), IsDeleted(n, false)
    {
        LogN = 1 + ceil(log2(n));
        lcapar = vector < vector<int> > (n, vector <int> (LogN, -1));
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d",&u, &v);
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        LCAPreprrocess();
        Decompose(Root, -1);
    }
    /// LCA Part Starts
    void LCADFS (int u, int p) {
        for (auto v: graph[u]) {
            if (v != p) {
                lcapar[v][0] = u;
                level[v] = level[u] + 1;
                LCADFS(v, u);
            }
        }
        return;
    }

    void LCAPreprrocess () {
        level[Root] = 0;
        lcapar[Root][0] = 0;
        LCADFS(Root, Root);
        for (int i = 1; i < LogN; i++) {
            for (int j = 0; j < n; j++) {
                if (lcapar[j][i-1] != -1) {
                    lcapar[j][i] = lcapar[lcapar[j][i-1]][i-1];
                }
            }
        }
        return;
    }
     int LCA (int a, int b) {
        if (level[a] > level[b]) swap(a, b);
        int d = level[b] - level[a];
        for (int i = 0; i < LogN; i++) {
            if (d&(1<<i)) {
                b = lcapar[b][i];
            }
        }
        if (a == b) return a;

        for (int i = LogN - 1; i >= 0; i--) {
            if (lcapar[a][i] != lcapar[b][i]) {
                a = lcapar[a][i];
                b = lcapar[b][i];
            }
        }
        return lcapar[a][0];
    }
    ///LCA Part Ends

    ///Centroid Decomposition Part Start
    int SubTreeDFS(int u, int p)
    {
        subtree[u] = 1;
        int ret = 1;
        for(auto v : graph[u]) {
            if(v != p && !IsDeleted[v]) {
                SubTreeDFS(v, u);
                subtree[u] += subtree[v];
                ret += subtree[v];
            }
        }
        return ret;
    }
    int CentroidDFS (int u, int p, int &cnt) {
        for (auto v: graph[u]) {
            if (v != p && !IsDeleted[v] && subtree[v] > cnt/2)
                return CentroidDFS(v, u, cnt);
        }
        return u;
    }
    void Decompose(int root, int p)
    {
        int cnt = SubTreeDFS(root, root);
        int centroid = CentroidDFS(root, root, cnt);
        ctpar[centroid] = p;
        IsDeleted[centroid] = true;
        for(auto v : graph[centroid]) {
            if(v != p && !IsDeleted[v]) {
                Decompose(v, centroid);
            }
        }
        return;
    }
    ///Centroid Decomposition Part Ends
    int dist(int u, int v)
    {
        return level[u] + level[v] - 2 * level[LCA(u,v)];
    }
    /// Particular Problem Part
    vector <int> ans;
    void update(int u)
    {
        int from = u;
        while(from != -1)
        {
            ans[from] = min(ans[from], dist(u, from));
            from = ctpar[from];
        }
    }
    int query(int u)
    {
        int from = u;
        int ret = inf;
        while(from != -1)
        {
            ret = min(ret, ans[from] + dist(u, from));
            from = ctpar[from];
        }
        return ret;
    }
    void Solve(int q)
    {
        ans = vector <int> (n, inf);
        update(0);
        while(q--)
        {
            int t, u;
            scanf("%d %d",&t,&u);
            if(t == 1) update(u - 1);
            else printf("%d\n",query(u - 1));
        }
        return;
    }
};


int main() {
    //ios::sync_with_stdio(false);
    int n, m;
    scanf("%d %d",&n,&m);
    CentroidTree T(n);
    T.Solve(m);
    return 0;
}
