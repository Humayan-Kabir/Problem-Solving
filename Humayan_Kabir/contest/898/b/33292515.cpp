/*input
7
2
3
*/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    LL n,a,b;
    scanf("%lld %lld %lld",&n,&a,&b);
    LL x,y,foo = 0;
    for(LL i = 0; i<=10000000; i++)
    {
        LL now = a * i;
        if(now > n) break;
        LL left = n - now;
        if(left % b == 0)
        {
            foo = 1;
            x = i; y = left/b;
            break;
        }
    }
    if(!foo) printf("NO\n");
    else
    {
        printf("YES\n");
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
