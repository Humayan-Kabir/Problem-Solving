/*input
8
1 2 4 8 16 32 64 576
*/
#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL check(LL num)
{
	num = abs(num);
	LL sq = sqrt(num);
	return (sq * sq) == num;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	LL ara[10000];
	int n;
	cin >> n;
	LL ans = INT_MIN;
	for(int i = 1; i<=n; i++)
	{
		LL num;
		cin >> num;
		if(num < 0) 
		{
			ans = max(ans,num);
			continue;
		}
		if(!check(num)) ans = max(ans,num);
	}
	cout << ans << endl;
	return 0;
}