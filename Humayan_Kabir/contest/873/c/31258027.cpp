/*input
3 2 1
1 0
0 1
0 0
*/
#include <bits/stdc++.h>
using namespace std;
int ara[120][120],dummy[120][120];
int main(int argc, char const *argv[])
{
	vector< pair<int,int> > vt[120];
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
	{
		for(int j=1;j<=m; j++)
		{
			cin>>ara[i][j];
			dummy[i][j]=ara[i][j];
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			ara[i][j]=ara[i-1][j]+ara[i][j];
		}
	}
	for(int j=1; j<=m; j++)
	{
		int prev=0;

		for(int i=1; i<=n; i++)
		{
			if(dummy[i][j]==0) continue;
            int now=ara[min(i+k-1,n)][j]-ara[i-1][j];
            vt[j].push_back(make_pair(-now,prev));
            prev+=dummy[i][j];
		}
	}
	int ans=0,move=0;
	for(int j=1; j<=m; j++)
	{
		sort(vt[j].begin(),vt[j].end());
		
		for(int i=0; i<vt[j].size();j++)
		{
			int x=vt[j][i].first*-1;
			if (x==0)
			{
				break;
			}
			else 
			{
				ans+=x;
                move+=vt[j][i].second;
                break;
			}
		}
	}

	cout<<ans<<" "<<move<<endl;

	return 0;
}