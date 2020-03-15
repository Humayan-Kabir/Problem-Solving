/*input
1
58
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{ 
	ios_base::sync_with_stdio(false);
	LL n,m;
	cin >> n >> m;
	if(n >= 62)
	{
		cout << m << endl;
	}
	else
	{
		LL now = 1LL << n;
		cout << m % now << endl;
	}
	return 0;
}