/*input
3 4
2 5 6
1 3 6 8
*/
#include<bits/stdc++.h>
#define mx 100007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int n, m;
LL header[mx], track[mx];
int check(LL Time)	
{
	int mark[mx];
	memset(mark,0,sizeof mark);
	int trackpos = 1;
	for(int i = 1; i<=n; i++)
	{
		if(trackpos > m) break;
		if(track[trackpos] <= header[i])
		{
			LL need = header[i] - track[trackpos];
			if(need<=Time)
			{
				mark[trackpos] = 1;
				LL A = max(0LL,Time - 2 * need);
				LL B = (Time - need) / 2;
				LL left = header[i] + max(A,B);
				trackpos++;
				while(1)
				{
					if(trackpos > m) break;
					if(track[trackpos]<=left) 
					{
						mark[trackpos] = 1;
						trackpos++;
					}
					else break;
				}
			}
		}
		else
		{
			LL left = header[i] + Time;
			while(1)
			{
				if(trackpos > m) break;
				if(track[trackpos]<=left) 
				{
					
					mark[trackpos] = 1;
					trackpos++;
					
				} 
				else break;
			}
		}
	}

	for(int i = 1; i<=m; i++) if(!mark[i]) return 0;
	return 1;	
}
int main()
{
	//ios_base::sync_with_stdio(false);
	scanf("%d %d",&n,&m);
	for(int i = 1; i<=n; i++) scanf("%lld",&header[i]);
	for(int i = 1; i<=m; i++) scanf("%lld",&track[i]);
	sort(header + 1,header + n + 1);
	sort(track + 1,track + m + 1);
	LL low = 0, high = 100000000000000;
	LL ans = INT_MAX;
	while(low <= high)
	{
		LL mid = (low + high) / 2;
		if(check(mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}	
	printf("%lld\n",ans);
    return 0;
}