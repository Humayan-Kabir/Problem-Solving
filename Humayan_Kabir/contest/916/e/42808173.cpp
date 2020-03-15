/*input
4
1 2
2 3
1 4
2
1 4 2
2 4 2
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int n, sparse_table[mx][18], parent[mx], level[mx], dist[mx], ara[mx], st[mx], en[mx], Timer = 0;
vector<int> graph[mx];
void dfs(int u,int par,int dis)
{
    st[u] = ++Timer;
    parent[u] = par;
    dist[u] = level[u] = dis;
    for(int v: graph[u])
        if(par!=v)
            dfs(v,u,dis+1);
    en[u] = Timer;
}
void ini()
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<18; j++)
        {
            sparse_table[i][j] = -1;
        }
    }
}
void make_table()
{
    for(int i = 1; i<=n; i++)
    {
        sparse_table[i][0] = parent[i];
    }
    for(int j = 1; j<18; j++)
    {
        for(int i = 1; i<=n; i++)
        {
            if(sparse_table[i][j - 1] != -1)
            sparse_table[i][j] = sparse_table[sparse_table[i][j-1]][j-1];
        }
    }
}

int query(int p,int q)
{
    if(level[p]<level[q]) swap(p,q);
    for(int j = 17; j>=0; j--)
    {
        if(level[p] - (1<<j) >=level[q])
        {
            p = sparse_table[p][j];
        }
    }
    if(p == q) return p;
    for(int j = 17; j>=0; j--)
    {
        if(sparse_table[p][j] != -1 && sparse_table[p][j] != sparse_table[q][j])
        {
            p = sparse_table[p][j];
            q = sparse_table[q][j];
        }
    }
    return parent[p];
}
int calculate_dist(int a, int b)
{
    int lca = query(a,b);
    return dist[a] + dist[b] - 2*dist[lca];
}
LL getSum(LL BITree[], LL index)
{
    LL sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(LL BITree[], LL n, LL index, LL val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}
LL sum(LL x, LL BITTree1[], LL BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}
void updateRange(LL BITTree1[], LL BITTree2[], LL n,
                 LL val, LL l, LL r)
{
    updateBIT(BITTree1,n,l,val);
    updateBIT(BITTree1,n,r+1,-val);
    updateBIT(BITTree2,n,l,val*(l-1));
    updateBIT(BITTree2,n,r+1,-val*r);
}

LL rangeSum(LL l, LL r, LL BITTree1[], LL BITTree2[])
{
    return sum(r, BITTree1, BITTree2) -
           sum(l-1, BITTree1, BITTree2);
}


LL *constructBITree(LL n)
{
    LL *BITree = new LL[n+1];
    for (LL i=1; i<=n; i++)
        BITree[i] = 0;

    return BITree;
}
int find_curLca(int a, int b, int c)
{
    vector< pair<int,int> > vv;
    int lca = query(a,b);
    int dis = dist[a] + dist[b] - 2*dist[lca] + calculate_dist(lca,c);
    vv.push_back({dis,lca});
    lca = query(b,c);
    dis = dist[b] + dist[c] - 2*dist[lca] + calculate_dist(lca,a);
    vv.push_back({dis,lca});
    lca = query(c,a);
    dis = dist[c] + dist[a] - 2*dist[lca] + calculate_dist(lca,b);
    vv.push_back({dis,lca});
    sort(vv.begin(), vv.end());
    return vv[0].second;
}
bool isAncestor(int root, int u)
{
    return (st[root] <= st[u] && en[u] <= en[root]);
}
int up(int till, int cur)
{
    for(int i = 17; i >= 0; i--)
    {
        if(level[cur] - (1<<i) > level[till])
            cur = sparse_table[cur][i];
    }
    return cur;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for(int i = 1; i<=n; i++) cin >> ara[i];
    for(int i = 1; i<n; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ini();
    dfs(1,-1,1);
    make_table();
    LL *BITTree1, *BITTree2;
    BITTree1 = constructBITree(n);
    BITTree2 = constructBITree(n);
    for(int i = 1; i<=n; i++)
    {
        updateRange(BITTree1, BITTree2, n, ara[i], st[i] - 1, st[i] - 1);
    }
    int gRoot = 1, curRoot = 1;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            cin >> curRoot;
        }
        else if(t == 2)
        {
            int u, v, x;
            cin >> u >> v >> x;
            int lca = find_curLca(curRoot, u, v);
            if(lca == curRoot)
            {
                updateRange(BITTree1,BITTree2, n, x, 0, Timer - 1);
            }
            else if(isAncestor(curRoot, lca))
            {
                updateRange(BITTree1, BITTree2, n, x, st[lca] - 1, en[lca] - 1);
            }
            else
            {
                if(!isAncestor(lca, curRoot))
                {
                    updateRange(BITTree1, BITTree2, n, x, st[lca] - 1, en[lca] - 1);
                }
                else
                {
                    int up_till_child_of_lca = up(lca, curRoot);
                    updateRange(BITTree1, BITTree2, n, x, 0, Timer - 1);
                    updateRange(BITTree1, BITTree2, n, -x, st[up_till_child_of_lca] - 1, en[up_till_child_of_lca] - 1);
                }

            }
        }
        else
        {
            int v;
            cin >> v;
            if(v == curRoot)
            {
                cout << rangeSum(0, Timer - 1, BITTree1, BITTree2) << endl;
            }
            else if(isAncestor(curRoot, v) || !isAncestor(v, curRoot))
            {
                cout << rangeSum(st[v] - 1, en[v] - 1, BITTree1, BITTree2) << endl;
            }
            else
            {
                int up_till = up(v, curRoot);
                cout << rangeSum(0, Timer - 1, BITTree1, BITTree2) - rangeSum(st[up_till] - 1, en[up_till] - 1, BITTree1, BITTree2) << endl;
            }
        }
    }
    return 0;
}
