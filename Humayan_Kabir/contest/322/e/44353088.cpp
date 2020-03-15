#include<bits/stdc++.h>
using namespace std;

struct CentroidTree
{
    vector < set<int> > graph;
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
            graph[u - 1].insert(v - 1);
            graph[v - 1].insert(u - 1);
        }
        LCAPreprrocess();
        Decompose(Root, -1);
    }
    /// LCA Part Starts
    void LCADFS (int u, int p)
    {
        for (auto v: graph[u])
        {
            if (v != p)
            {
                lcapar[v][0] = u;
                level[v] = level[u] + 1;
                LCADFS(v, u);
            }
        }
        return;
    }

    void LCAPreprrocess ()
    {
        level[Root] = 0;
        lcapar[Root][0] = 0;
        LCADFS(Root, Root);
        for (int i = 1; i < LogN; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (lcapar[j][i-1] != -1)
                {
                    lcapar[j][i] = lcapar[lcapar[j][i-1]][i-1];
                }
            }
        }
        return;
    }
    int LCA (int a, int b)
    {
        if (level[a] > level[b])
            swap(a, b);
        int d = level[b] - level[a];
        for (int i = 0; i < LogN; i++)
        {
            if (d&(1<<i))
            {
                b = lcapar[b][i];
            }
        }
        if (a == b)
            return a;

        for (int i = LogN - 1; i >= 0; i--)
        {
            if (lcapar[a][i] != lcapar[b][i])
            {
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
        for(auto v : graph[u])
        {
            if(v != p && !IsDeleted[v])
            {
                SubTreeDFS(v, u);
                subtree[u] += subtree[v];
                ret += subtree[v];
            }
        }
        return ret;
    }
    int CentroidDFS (int u, int p, int &cnt)
    {
        for (auto v : graph[u])
        {
            if (v != p && subtree[v] > cnt/2)
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
        for(auto v : graph[centroid])
        {
            graph[v].erase(centroid);
            Decompose(v, centroid);
        }
        return;
    }
    ///Centroid Decomposition Part Ends
    int dist(int u, int v)
    {
        return level[u] + level[v] - 2 * level[LCA(u,v)];
    }
    /// Particular Problem Part
    void Solve()
    {
        for(int i = 0; i<n; i++)
        {
            int to = i, up = 0;
            while(to != -1)
            {
                up++; to = ctpar[to];
            }
            if(i) printf(" ");
            printf("%c",'A' + up - 1);
        }
        printf("\n");
    }
};
int main()
{
    int n;
    scanf("%d",&n);
    CentroidTree T(n);
    T.Solve();
}
