#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,k;
int color[N];
set<int> used;
set<int> data[N];
struct DisjointSet
{
   int node;
   vector<int> parents,rank;
   DisjointSet(int _node)
   {
       node=_node;
       for(int i=0;i<=_node;i++)
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
int main()
{
  ios_base::sync_with_stdio(false);

  cin>>n>>m>>k;
  for(int i=1;i<=n;i++) cin>>color[i];

  DisjointSet D(n+5);

  for(int i=1;i<=m;i++)
  {
     int u,v;
     cin>>u>>v;
     D.Union(u,v);
     used.insert(u);
     used.insert(v);
  }

  set<int> a;

  int cnt=0;

  for(int u:used)
  {
      int x=D.Find(u);
      data[x].insert(u);
      a.insert(x);
  }
  int total=0;

  for(int u:a)
  {
      int ans=0;
      map<int,int> mymap;
      for(int v:data[u])
      {
        mymap[color[v]]++;
        ans=max(ans,mymap[color[v]]);
      }

      total+=(data[u].size()-ans);

  }

  cout<<total<<endl;

  return 0;

}
