/*input
5
10 20 30 40 50
1 1 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
int ara[400],cost[400],n;
map<int,int> dp[402];
int rec(int pos,int g)
{
	if(g==1) return 0;
	if(pos==n) 
	{
		if(g==1) return 0;
		else return 1000000;
	}
	if (dp[pos].find(g)!=dp[pos].end())
	{
		return dp[pos][g];
	}
	int now=1000000;
	now=rec(pos+1,g);
	now=min(now,cost[pos]+rec(pos+1,__gcd(g,ara[pos])));
	return dp[pos][g]=now;
}
int main(int argc, char const *argv[])
{
	
	cin>>n;
	for(int i = 0; i<n; i++) cin>>ara[i];
	for(int i = 0; i<n; i++) cin>>cost[i];		
    int ans=rec(0,0);
    if(ans>=1000000) cout<<-1<<endl;
    else cout<<ans<<endl;
	return 0;
}