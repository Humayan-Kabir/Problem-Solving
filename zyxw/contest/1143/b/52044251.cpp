
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
Long dp[2][2][20];
int vis[2][2][20];
int lim, tt = 0;
vector<int> inp;

Long DP(int pos, int isSmall, int isStart)
{
    if (pos == lim)
        return 1;
    Long &ret = dp[isSmall][isStart][pos];
    int &v = vis[isSmall][isStart][pos];
    if (v == tt)
        return ret;
    v = tt;
    int ses = isSmall ? 9 : inp[pos];
    int i;
    ret = 0;
    Long ans = 1;
    if (!isStart)
        for (i = 0; i <= ses; i++)
        {
            ans = max(ans, 1LL * i * DP(pos + 1, isSmall | i < inp[pos], 0));
        }
    else
    {
        for (i = 1; i <= ses; i++)
        {
            ans = max(ans, 1LL * i * DP(pos + 1, isSmall | i < inp[pos], 0));
        }
        ans = max(ans, DP(pos + 1, 1, 1));
    }
    return ret = ans;
}

Long Cal(Long x)
{
    if (x <= 9)
        return x;
    inp.clear();
    while (x)
    {
        inp.push_back(x % 10);
        x /= 10;
    }
    reverse(inp.begin(), inp.end());
    lim = inp.size();
    tt++;
    return DP(0, 0, 1);
}
int main(int argc, char const *argv[])
{
    Long n;
    cin >> n;
    cout << Cal(n) << endl;
    return 0;
}
