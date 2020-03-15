/*input
1
2
3
5
*/
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int cost[5][5];
int dp[500][4];
int rec(int n,int prev)
{
   if(n==0) return 0;
   int &ret=dp[n][prev];
   if(ret!=-1) return ret;
   int now=INT_MAX;
   if(prev==-1)
   {
     now=min(now,0+rec(n-1,1));
   }
   else
   {
       for(int i=1 ; i<=3; i++)
       {
         if(i==prev) continue;
         now=min(now,cost[prev][i]+rec(n-1,i));
       }

   }

   return ret=now;
}
int main(int argc, char const *argv[])
{
    memset(cost,0,sizeof cost);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cost[1][2]=a;
    cost[2][1]=a;
    cost[1][3]=b;
    cost[3][1]=b;
    cost[2][3]=c;
    cost[3][2]=c;
    memset(dp,-1,sizeof dp);
    cout<<rec(n,-1)<<endl;
    return 0;
}
