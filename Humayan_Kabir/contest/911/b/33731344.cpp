/*input
5 2 3
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    int n,a,b;
	cin >> n >> a >> b;
	int ans = 1;
	for(int i = 1; i<n; i++)
	{
		int x = i, y = n - i;
		int now1 = a / x;
		int now2 = b / y;
		if(now1 > 0 && now2 > 0) ans = max(ans,min(now2,now1));
	}
	cout << ans << endl;
	return 0;
}