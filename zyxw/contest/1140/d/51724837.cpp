#include <bits/stdc++.h>
#define mod 1000000007
#define mx 2000007
using namespace std;
typedef long long int LL;
LL INF = 1000000000000000000;
LL fun(int i, int j, int k) {
    LL ret = 1LL * (i + 1) * (j + 1) * (k + 1);
    return ret;
}
LL DP_FUNC(int n)
{
    if (n < 3)
        return 0;
    LL table[n][n];
    for (int l = 0; l < n; l++)
    {
        for (int i = 0, j = l; j < n; i++, j++)
        {
            if (j < i + 2)
                table[i][j] = 0;
            else
            {
                table[i][j] = INF;
                for (int k = i + 1; k < j; k++)
                {
                    LL x = table[i][k] + table[k][j] + fun(i, j, k);
                    if (table[i][j] > x)
                        table[i][j] = x;
                }
            }
        }
    }
    return table[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << DP_FUNC(n) << endl;
    return 0;
}
