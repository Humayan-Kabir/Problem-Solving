/*input
2 3
1 3
*/
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL bigmod(LL a, LL p, LL m)
{
	if(p == 0) return 1 % m;
	LL x = bigmod(a, p / 2, m);
	x = (x * x) % m;
	if(p & 1) x = (x * a) % m;
	return x;
}
LL inverse[55];
LL calculate(LL n, LL r) {
      if (r > n) return 0;
      if (n - r < r) r = n - r;
      n %= mod;
      LL ans = 1;
      for(int i = 0; i<r; i++) {
            ans = (ans * (n - i)) % mod;
            ans = (ans * inverse[i + 1]) % mod;
      }
      return ans;
}
void initialization()
{
	for(int i = 0; i<55; i++) 
		inverse[i] = bigmod(i, mod - 2, mod);
}
LL fi[30], s;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n >> s;
	for(int i = 0; i<n; i++) cin >> fi[i];
	LL ans = 0;
	initialization();	
	for(int i = 0; i<(1<<n); i++)
	{
		LL x = 0, cnt = 0;
		for(int j = 0; j<n; j++)
		{
			if(i & (1 << j))
			{
				cnt++;
				x += fi[j] + 1;
			}
		}
		if(s - x < 0) continue;
		LL temp = calculate(s - x + n - 1, n - 1);
        if (cnt & 1) temp = - temp;
        ans = (ans + temp) % mod;
        if (ans < 0) ans += mod;
	}
	cout << ans << endl;	
	return 0;
}