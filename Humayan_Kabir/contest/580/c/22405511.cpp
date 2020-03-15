#include<bits/stdc++.h>
using namespace std;
int cat[100003],vis[100002],k,t;
vector<int> adj[100003];

void dfs(int nod,int n_cat){
int sz=adj[nod].size();
n_cat+=cat[nod];
//cout<<"node "<< nod<<" n_cat "<< n_cat<<endl;
if(n_cat>k) return;
if(sz==1 && nod!=1){
    //cout<<"loop node "<< nod<<" n_cat "<< n_cat<<endl;
    t++;
    return;
}
//cout<<"node "<< nod<<" n_cat "<< n_cat<<endl;
for (int i=0;i<sz ;i++ )
{
   if(vis[adj[nod][i]]==0){
     vis[adj[nod][i]]=1;
    if(cat[adj[nod][i]]==1){
      // cout<<"cat"<<" node "<<adj[nod][i]<< " "<<cat[adj[nod][i]]<<endl;
      dfs(adj[nod][i],n_cat);
    }
    else
      dfs(adj[nod][i],0);
   }
}

}
int main()
{
    int node,m,i,j,c,x,y;
    while (cin>>node>>k)
    {
       memset(vis,0,sizeof vis);
       for (i=1;i<=node ;i++ )
       {
          scanf("%d",&c);
            cat[i]=c;
       }
      // cout<<cat[2]<<endl;
       for (i=1;i<=node-1 ;i++ )
       {
          scanf("%d %d",&x,&y);
          adj[x].push_back(y);
          adj[y].push_back(x);
       }
       t=0;
       vis[1]=1;
       dfs(1,0);
       cout<<t<<endl;
     for (i=1;i<=node-1 ;i++ )
     {
        adj[i].clear();
     }


    }

    return 0;
}
