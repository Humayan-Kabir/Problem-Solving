#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int dp[N][N], inp[N], n;
int DP(int left, int right)
{
    int &ret = dp[left][right];
    if (ret != -1)
        return ret;
    if (left > right)
        return 0;
    ret = DP(left + 1, right) + 1;
    int i;
    for (i = left + 1; i <= right; i++)
    {
        if (inp[left] == inp[i])
            ret = min(ret, DP(left + 1, i) + DP(i + 1, right));
    }
    return ret;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        inp[i] = ch - 'a';
    }
    memset(dp, -1, sizeof dp);
    cout << DP(0, n - 1) << endl;
    return 0;
}