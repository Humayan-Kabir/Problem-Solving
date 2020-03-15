#include<bits/stdc++.h>
using namespace std;
int adj[3000],t;
int Find(int m){
 t++;
if(adj[m]==-1) return t;
return Find(adj[m]);
}
int main()
{
  int n,i,num,x;
  while (scanf("%d",&n)!=EOF)
  {
    // memset(vis,0,sizeof vis);
     x=0;
     for (i=1;i<=n ;i++ )
     {
        scanf("%d",&num);
        adj[i]=num;
     }
     for (i=1;i<=n ;i++ ){
        t=0;
        x=max(x,Find(i));
     }
    printf("%d\n",x);
  }
   return 0;
}
