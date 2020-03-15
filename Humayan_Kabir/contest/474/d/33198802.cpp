/*input
3 2
*/
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL dp[100007],n,k;
int main(int argc, char const *argcv[])
{
	cin >> n >> k;
	for(LL i = 1; i<=100000; i++)
    {
        if(i < k) {dp[i] = 1; continue;}
        if(i == k) {dp[i] = 2;continue;}
        dp[i] = (dp[i-1] + dp[i-k]) % mod;
    }
    for(int i = 1; i<=100000; i++)
        dp[i] = (dp[i-1] + dp[i]) % mod;
    for(int i = 1; i<=n; i++)
    {

        int x,y;
        cin >> x >> y;
        LL now = (dp[y] - dp[x-1] + mod) % mod;
        cout << now << endl;
    }
	return 0;
}
