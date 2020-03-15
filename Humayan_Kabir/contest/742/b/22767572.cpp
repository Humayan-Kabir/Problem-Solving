#include<bits/stdc++.h>
#define mx 100002
using namespace std;
int main()
{
    long long int ara[mx],flag[mx],n,k,i,j,ans;
    while (cin>>n>>k)
    {
        memset(flag,0,sizeof flag);
       for (i=0;i<n ;i++ )
       {
          scanf("%d",&ara[i]);
          flag[ara[i]]++;
       }
       ans=0;
       for (i=0;i<n ;i++ )
       {
          j=ara[i]^k;
          flag[ara[i]]--;
          if(j>100000) continue;
         // cout<<j<<" "<<flag[j]<<endl;
          if(flag[j]>0){
            ans+=flag[j];
          }
       }
       cout<<ans<<endl;
    }

    return 0;
}
