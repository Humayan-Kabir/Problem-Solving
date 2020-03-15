#include <bits/stdc++.h>
using namespace std;
struct DisjoinSet
{
    int node;
    std::vector<long long int> rank,parents,sum;
    DisjoinSet(int _node)
    {
        node=_node;
        for(int i=0; i<=node;	i++)
        {
            rank.push_back(0);
            parents.push_back(i);
            sum.push_back(-1);

        }
    }
    int Find(int n)
    {
        if(parents[n]==n) return n;
        return parents[n]=Find(parents[n]);
    }
    long long int Union(int a,int b)
    {
        int u=Find(a);
        int v=Find(b);
        if(u!=v)
        {
            if(rank[u]==rank[v])
            {
                rank[u]++;
                parents[v]=u;
                sum[u]+=sum[v];
                return sum[u];
            }
            else if(rank[u]>rank[v])
            {
                parents[v]=u;
                sum[u]+=sum[v];
                return sum[u];
            }
            else
            {
                parents[u]=v;
                sum[v]+=sum[u];
                return sum[v];
            }
        }

    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    DisjoinSet D(n);
    vector<long long int> ans;
    long long int result,ara[n+2],indx[n+2];

    for(int i=1; i<=n; i++) cin>>ara[i];
    for(int i=1; i<=n; i++) cin>>indx[i];

    ans.push_back(0);
    long long int mx=-1111111111111;

    for(int i=n; i>=2; i--)
    {
        int id=indx[i],flag=0;
        D.sum[id]=ara[id];

        if((id+1)<=n && D.sum[id+1]!=-1) mx=max(mx,D.Union(id+1,id));

        if((id-1)>=1 && D.sum[id-1]!=-1) mx=max(mx,D.Union(id-1,id));

        mx=max(mx,ara[id]);

        ans.push_back(mx);
    }
    for(int i=n-1; i>=0; i--)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
