/*input
1 1 1
.
*/
#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
string str[2002];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i<n; i++) cin >> str[i];
	int ans = 0;
/*	if(n == 1 && m == 1)
	{
		if(str[0][0] == '.')
		{
			printf("1\n");
		}
		else 
		{
			printf("0\n");
		}
		return 0;
	}*/	
	for(int i = 0; i<n; i++)
	{
		int cnt = 0;
		for(int j = 0; j<m; j++)
		{
			if(str[i][j] == '.')
			{
				cnt++;
			}
			else 
			{
				ans+=max(0,cnt - k + 1);
				cnt = 0;
			} 
		}
		ans+=(max(0,cnt - k + 1));
	}
	for(int j = 0; j<m; j++)
	{
		int cnt = 0;
		for(int i = 0; i<n; i++)
		{
			if(str[i][j] == '.')
			{
				cnt++;
			}
			else 
			{
				ans+=max(0,cnt - k + 1);
				cnt = 0;
			} 
		}
		ans+=max(0,cnt - k + 1);
	}	
	if(k == 1) ans = ans / 2;
	printf("%d\n",ans);
	return 0;
}