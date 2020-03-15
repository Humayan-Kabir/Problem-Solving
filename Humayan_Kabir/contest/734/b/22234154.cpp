#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 long long int a,b,i,j,k,cas=1,ans,t,ara[5];
  while (scanf("%lld%lld%lld%lld",&a,&b,&i,&j)!=EOF)
  {
     ara[0]=a;
     ara[1]=i;
     ara[2]=j;
     sort(ara,ara+3);
     //cout<<ara[0];
     ans=0;
     for (i=1;i<=ara[0] ;i++ )
     {
        ans+=256;
     }
     if(a>ara[0]){
        k=a-ara[0];
        k=min(k,b);
        for (i=1;i<=k ;i++ )
        {
           ans+=32;
        }
     }
     cout<<ans<<endl;
  }

 return 0;
}
