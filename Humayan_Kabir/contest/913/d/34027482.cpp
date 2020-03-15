/*input
2 100
2 42
2 58
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector< pair<int,pair<int,int> > > vv;
int n,t;
int check(int mid)
{
	int cnt = 0;
	int timer = t;
	for(int i = 0; i<n; i++)
	{
		if(vv[i].second.first>=mid)
		{
			int need = vv[i].first;
			if(need<=timer)
			{
				cnt++;
				timer = timer - need;
			}
		}
	}
	if(cnt>=mid) return 1;
	return 0;
}
int main(int argc, char const *argv[])
{ 
	ios_base::sync_with_stdio(false);
	cin >> n >> t;
	for(int i = 1; i<=n; i++)
	{
		int u,v;
		cin >> u >> v;
		vv.push_back({v,{u,i}});
	}
	sort(vv.begin(), vv.end());
	int ans = 0,low = 1,high = n;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(check(mid))
		{
			ans = mid;
			low =  mid + 1;
		}
		else high = mid - 1;
	}
	cout << ans << endl;
	cout << ans << endl;
	int foo = 0;
	int cnt = 0;
	int timer = t;
	for(int i = 0; i<n; i++)
	{
		if(vv[i].second.first>=ans)
		{
			int need = vv[i].first;
			if(need<=timer && cnt<ans)
			{
				cnt++;
				timer = timer - need;
				if(foo) cout <<" "<<vv[i].second.second;
				else cout<< vv[i].second.second;
				foo = 1;
			}
		}
	}
	return 0;
}