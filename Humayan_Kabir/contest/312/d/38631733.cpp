/*input
6 3
11
11
11
24
26
100
*/
#include <bits/stdc++.h>
#define mx 100002
#define infinity 1111111111111111111ll
using namespace std;
typedef long long int LL;
LL n, m, g, ara[mx], dp[mx][101], sum[mx], dist[mx];
LL cost(int i,int j)
{
    return (ara[j]) * (j - i + 1) - (sum[j] - sum[i - 1]);
}
void rec(int g,int l,int r,int kl,int kr)
{
    if(l > r) return;
    int mid = (l + r) / 2;
    dp[mid][g] = infinity;
    int bestk = -1;
    for(int i = kl; i<=kr; i++)
    {
        if(i > mid) break;
        LL now = dp[i][g - 1] + cost(i + 1,mid);
        if(now < dp[mid][g])
        {
            dp[mid][g] = now;
            bestk = i;
        }
    }
    rec(g, l, mid - 1, kl, bestk);
    rec(g, mid + 1, r, bestk, kr);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> g;
    for(int i = 2; i<=n; i++)
    {
        cin >> dist[i];
        dist[i] = dist[i] + dist[i - 1];
    }
    for(int i = 1; i<=m; i++)
    {
        LL hi, ti;
        cin >> hi >> ti;
        ara[i] = ti - dist[hi];
    }
    sort(ara + 1, ara + m + 1);
    for(int i = 1; i<=m; i++)
        sum[i] = sum[i - 1] + ara[i];
    for(int i = 1; i<=m; i++) dp[i][1] = cost(1,i);
    for(int i = 2; i<=g; i++)
    {
        rec(i,1,m,1,m);
    }
    cout << dp[m][g] << endl;
    return 0;
}
