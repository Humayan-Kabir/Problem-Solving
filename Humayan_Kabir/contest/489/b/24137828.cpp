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

int main()
{

    int ar[101],arr[101],fl[101],i,j,k,n,m,flag;
    while (sf1(n)==1)
    {
        flag=0;
        for (i=0; i<n ; i++ )
        {
            sf1(ar[i]);
        }
        sort(ar,ar+n);
        sf1(m);
        for (i=0; i<m ; i++ )
        {
            sf1(arr[i]);
        }
        sort(arr,arr+m);
        memset(fl,0,sizeof fl);
        for (i=0;i<n ;i++ )
        {
           for (j=0;j<m ;j++ )
           {
               if(fl[j]==0){
                if(abs(ar[i]-arr[j])<=1) {
                        flag++;
                        fl[j]=1;
                        break;
               }
           }
        }
        }
        printf("%d\n",flag);
    }
    return 0;
}
