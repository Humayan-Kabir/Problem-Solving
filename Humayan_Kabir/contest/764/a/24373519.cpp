#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

int main(){

int ara[10010],i,j,k,n,m;
while (sf3(n,m,k)==3)
{
   memset(ara,0,sizeof ara);
   for (i=m;i<=k ;i+=m )
   {
      ara[i]=1;
   }
  // FOR1(i,k) cout<<ara[i]<<endl;
  int f=0;
   for (i=n;i<=k ;i+=n )
   {
      if(ara[i]==1){
        ara[i]=0;
        f++;
        //cout<<i<<endl;
      }
   }
   printf("%d\n",f);
}
return 0;
}
