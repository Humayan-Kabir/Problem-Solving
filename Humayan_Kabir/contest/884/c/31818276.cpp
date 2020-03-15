/*input
5
1 5 4 3 2
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100007];
vector< pair<int,pair<int,int> > > data;
int vis[100007];
void dfs(int u,int cnt)
{
	vis[u]=1;
	for(int v : graph[u])
	{
        if(vis[v]==1)
        {
        	data.push_back({-cnt,{v,u}});
        }
        else dfs(v,cnt+1); 
	}
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		int u;
		scanf("%d",&u);
		graph[i].push_back(u);
	}
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i]) dfs(i,1);
	}
    sort(data.begin(), data.end());
    long long ans = 0;
    //cout<<data[0].first<<" "<<data[1].first<<endl;
    if(data.size()>=2)
    {
        ans+=(1LL*data[0].first+data[1].first)*(1LL*data[0].first+data[1].first);
        for(int i = 2; i<data.size(); i++)
        ans+=(1LL*data[i].first*data[i].first); 
    }
    else ans+=(1LL*data[0].first*data[0].first);  
    cout<<ans<<endl;
	return 0;
}