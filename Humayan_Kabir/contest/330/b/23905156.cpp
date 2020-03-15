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

int ara[1010];
int Search(int n)
{
    int i;
    FOR1(i,n)
    {
        if(ara[i]==0) return i;
    }

}
int main()
{

    int n,m,i,j,k;
    while (sf2(n,m)==2)
    {
        memset(ara,0,sizeof ara);
        while (m--)
        {
            sf2(i,j);
            ara[i]=1;
            ara[j]=1;
        }
       k=Search(n);
       printf("%d\n",n-1);
       FOR1(i,n){
         if(i!=k){
            printf("%d %d\n",i,k);
         }
       }

    }
  return 0;

}


