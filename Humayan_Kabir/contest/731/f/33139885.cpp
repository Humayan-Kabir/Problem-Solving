/*input
4
8 2 2 7
*/
#include <bits/stdc++.h>
#define mx 200003
using namespace std;
typedef long long int LL;
LL ara[mx],cnt[2*mx],ar[mx];
LL mark[mx];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		scanf("%lld",&ar[i]);
		cnt[ar[i]]++;
		mark[ar[i]] = 1;
	}
	cnt[0] = 0;
	for(int i = 1; i<2*mx; i++)
		cnt[i] = cnt[i] + cnt[i-1];
	LL ans = 0;
	for(LL i = 1; i<mx; i++)
	{
		if(mark[i])
		{
			LL now = 0;
			//cout <<" INSIDE "<<i<<endl;
			for(LL j = i; j<mx; j+=i)
			{
				//cout <<"now in "<<j<<" cnt is" <<cnt[j+i -1] - cnt[j-1]<<endl;
				now += 1LL*(cnt[j+i-1] - cnt[j-1]) * j;
			}
			ans = max(ans,now);
		}
	}
	printf("%lld\n",ans);
	return 0;
}