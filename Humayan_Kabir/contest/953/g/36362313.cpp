/*input
3
11 4 10
*/
#include <bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int odd = 0, even = 0;
	for(int i = 1; i<=n; i++)
	{
		int num;
		scanf("%d",&num);
		if(num & 1) odd++;
		else even++;
	}
	int ans = min(odd,even) + max(0,odd - even) / 3;
	printf("%d\n",ans);
	return 0;
}