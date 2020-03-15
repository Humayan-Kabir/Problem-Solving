/*input
2
1 2
*/
#include <bits/stdc++.h>
#define mx 1000007
#define fs first
#define sc second
using namespace std;
typedef long long int LL;
int cnt[mx],ara[mx];
vector<int> vv[1000007];
int main(int argc, char const *argv[])
{ 
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		int num;
		scanf("%d",&num);
		vv[num].push_back(i);
	}
	long double ans = 0.0;
    long double prob = 2.0/(1.0 * n *n);

	for(int i = 1; i<=1000000; i++)
	{
		long long way = 0;
		for(int j = 0; j<vv[i].size(); j++)
		{
			if(j == 0)
			{
				way+=(1LL * vv[i][j] * (n - vv[i][j] + 1));
			}
			else
			{
				way+=(1LL * (vv[i][j] - vv[i][j-1]) * (n - vv[i][j] + 1));
			}
		}
		long long siz = vv[i].size();
		ans+=((1.0 * siz) * prob) / 2.0;
		way -= siz;
		ans+=((1.0 * way) * prob);
	}	
	cout << fixed << setprecision(10) << ans <<endl;
	return 0;
}