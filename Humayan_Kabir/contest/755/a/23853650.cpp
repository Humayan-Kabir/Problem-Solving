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
#define mx 10100
using namespace std;
typedef long long int lint;
typedef double dbl;
int state[(mx/32)+5],sz;
vector<int> prime;
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}
void bit_seive(){
   int i,j,root;
   root=sqrt(mx);
   for (i=3;i<=root ;i+=2 )
   {
      if(Check(state[i>>5],i&31)==0){
        for (j=i*i;j<=mx ;j+=(2*i))
        {
            int m=i*j;
           state[j>>5]=Set(state[j>>5],j&31);
        }
      }
   }
   prime.push_back(2);

}

int main(){

bit_seive();
long long int n,k,i,j;
while (sf1ll(n)==1)
{
   if(n==1){
    printf("%d\n",3);
    continue;
   }
   if(n==2){
    printf("%d\n",4);
    continue;
   }
   if(n%2!=0){
    printf("%d\n",1);
    continue;
   }
   else{
    for (i=1;i<=1000 ;i++ )
    {
       k=(i*n)+1;
       if(k%2==0)
        break;
       if(Check(state[k>>5],k&31)!=0)
        break;
    }
    printf("%d\n",i);
   }
}
return 0;
}

