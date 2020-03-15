/*input
2 1
99 100
98 99
*/
#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	//ios_base::sync_with_stdio(false);
	long double ans = 100000000000.0;
	int n;
	cin >> n;
	long double m;
	cin >> m;
	while(n--)
	{
		long double a,b;
		cin >> a >> b;
		long double now = (a * m) / b;
		ans = min(ans,now);
	}
	cout << setprecision(10)<<fixed<<ans << endl;
	return 0;
}