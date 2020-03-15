#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,x,y,ara[111],ans,i,t,j;
while (cin>>n>>m)
{
   for (i=1;i<=n ;i++ )
   {
      scanf("%d",&ara[i]);
   }
   ans=0;
   for (i=1;i<=m ;i++ )
   {
      cin>>x>>y;
      t=0;
      for (j=x;j<=y ;j++ )
      {
         t+=ara[j];
      }
      if(t>0) ans+=t;
   }
  cout<<ans<<endl;

}
return 0;
}
