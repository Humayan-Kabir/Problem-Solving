#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct DisjointSet
{
    int node;
    vector<int> parents,rank;
    DisjointSet(int _node)
    {
        node=_node;
        for(int i=0; i<=_node; i++)
        {
            parents.push_back(i);
            rank.push_back(0);
        }
    }
    int Find(int n)
    {
        if(parents[n]==n) return parents[n];
        return parents[n]=Find(parents[n]);
    }
    void Union(int a,int b)
    {
        int u=Find(a);
        int v=Find(b);
        if(u!=v)
        {
            if(rank[u]==rank[v])
            {
                rank[u]++;
                parents[v]=u;
            }
            else if(rank[u]>rank[v])
            {
                parents[v]=u;
            }
            else
            {
                parents[u]=v;
            }
        }
    }
};
vector<int> ans[100007];

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> v1,v2;
    int cnt=0;
    map<int,int> mymap,mp;
    int n;
    cin>>n;
    DisjointSet D(n+10);
    for(int i=1; i<=n; i++)
    {
        int num;
        cin>>num;
        mymap[num]=i-1;
        v1.push_back(num);
        v2.push_back(num);
    }

    sort(v1.begin(),v1.end());

    for(int i=0; i<n; i++)
    {
        if(v1[i]!=v2[i])
        {
            int u=mymap[v1[i]];
            int v=mymap[v2[i]];
            swap(v2[u],v2[v]);
            D.Union(u+1,v+1);
        }
    }

    for(int i=1;i<=n;i++)
    {
        int p=D.Find(i);

        if(mp.find(p)==mp.end())
        {
            mp[p]=cnt;
            cnt++;
            ans[mp[p]].push_back(i);
        }
        else
        {
            ans[mp[p]].push_back(i);
        }
    }

    cout<<cnt<<endl;

    for(int i=0; i<cnt; i++)
    {
        int sz=ans[i].size();
        cout<<sz;
        for(int j=0; j<sz; j++)
        {
            cout<<" "<<ans[i][j];
        }

        cout<<endl;
    }

    return 0;


}
