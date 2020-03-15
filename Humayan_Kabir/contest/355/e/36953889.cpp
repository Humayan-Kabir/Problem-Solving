#include<bits/stdc++.h>
#define mx 2000001
using namespace std;
int ara[mx];
int main()
{
    int n, k, mn = mx;
    scanf("%d %d",&n,&k);
    for(int i = 1; i<=n; i++)
    {
        int num;
        scanf("%d",&num);
        ara[num]++;
        mn = min(mn, num);
    }
    for(int i = 1; i<mx; i++) ara[i] = ara[i - 1] + ara[i];
    int ans = 1;
    for(int i = 2; i<=mn; i++)
    {
        int now = 0;
        for(int j = i; j<=1000000; j+=i)
        {
            int last = min(j + i - 1, j + k);
            now = now + ara[last] - ara[j - 1];
        }
        if(now == n) ans = max(ans,i);
    }
    printf("%d\n",ans);
    return 0;
}
