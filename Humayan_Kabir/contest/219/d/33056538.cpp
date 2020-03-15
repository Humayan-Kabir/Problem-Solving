/*input
4
1 4
2 4
3 4
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
vector< pair<int,int> > graph[mx];
int n,ans[mx],numberofone = 0,root = 1, min_cost = INT_MAX;
void dfs(int u, int par)
{
	for(auto x : graph[u])
	{
		int v = x.first;
		if(v != par)
			dfs(v,u), numberofone+=x.second;
	}
} 
void rec(int u,int forward,int backward,int par)
{
	ans[u] = ans[root] - backward + forward;
	min_cost = min(min_cost,ans[u]);
	for(auto x : graph[u])
	{
		int v = x.first;
		if(v != par)
		{
			rec(v,forward + (x.second == 1),backward + (x.second == 0),u);
		}
	}
}
int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 1; i<n; i++)
	{
		int u,v;
		cin >> u >> v;
		graph[u].push_back({v,1});
		graph[v].push_back({u,0});
	}
	dfs(root,-1);
	ans[root] = n - 1 - numberofone;
	rec(root,0,0,-1);
	vector<int> vv;
	for(int i = 1; i<=n; i++)
		if(ans[i] == min_cost) vv.push_back(i);
	cout << min_cost << endl;
	for(auto v : vv) cout << v <<" ";
	return 0;
}