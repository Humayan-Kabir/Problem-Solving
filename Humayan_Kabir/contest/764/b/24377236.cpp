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
#define mx 100009
using namespace std;
typedef long long int lint;
typedef double dbl;

int main(){

int i,j,k,m,n;
int ara[3*mx];
while (sf1(n)==1)
{
   FOR1(i,n) sf1(ara[i]);
   if(n%2!=0){
    k=n/2;
    k++;
   }
   else{
    k=n/2;
   }
   for (i=1;i<=k ;i++ )
   {
     if(i%2!=0){
        int t=ara[i];
        ara[i]=ara[n-i+1];
        ara[n-i+1]=t;
     }
   }
   printf("%d",ara[1]);
   for (i=2;i<=n ;i++ )
   {
      printf(" %d",ara[i]);
   }
   printf("\n");
}

return 0;
}
