/*input
6 5
1 1 1 3 3
zacccd
1 1
3 3
4 1
6 1
1 2
*/
#include <bits/stdc++.h>
#define mx 500007
using namespace std;
vector<int> graph[mx];
vector< pair<int,int> > Query[mx];
int n, q, sz[mx], st[mx], ft[mx], height[mx], ver[mx], ans[mx], cnt[mx][26], odd[mx],Timer = 0;
string str;
void getSz(int u,int par)
{
	height[u] = height[par] + 1;
	st[u] = ++Timer;
	ver[Timer] = u;
	sz[u] = 1; 
	for(int v : graph[u])
		if(v != par)
			getSz(v,u), sz[u] += sz[v];

	ft[u] = Timer;	

}
inline void add(int Time)
{
    int v = ver[Time], h = height[v], col = str[v - 1] - 'a';
	cnt[h][col]++;
	if(cnt[h][col]&1) odd[h]++;
	else odd[h]--;
}
inline void remov(int Time)
{
	int v = ver[Time], h = height[v], col = str[v - 1] - 'a';
	cnt[h][col]--;
	if(cnt[h][col] % 2 == 0) odd[h]--;
	else odd[h]++;
}
void dfs(int u, int par,int keep)
{
	int MX = -1, bighChild = -1;
	for(int v : graph[u])
		if(v != par && sz[v] > MX)
			MX = sz[v], bighChild = v;

	for(int v : graph[u])
	    if(v != par && v != bighChild)
	    	dfs(v, u, 0);

	if(bighChild != -1) 
	     dfs(bighChild, u, 1);

	for(int v : graph[u])
	   if(v != par && v != bighChild)
	      for(int i = st[v]; i<=ft[v]; i++)
	         add(i);

	add(st[u]);

	for(auto qq : Query[u])
	{
		ans[qq.second] = (bool)(odd[qq.first] <= 1);
	}  

	if(keep == 0)
	{
		for(int i = st[u]; i<=ft[u]; i++)
			remov(i);
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 2; i<=n; i++)
	{
		int p;  cin >> p;
		graph[p].push_back(i);
		graph[i].push_back(p);
	}
	getSz(1,1);
	cin >> str;
	for(int i = 1; i<=q; i++)
	{
		int v, hh;
		cin >> v >> hh;
		Query[v].push_back({hh, i});
	}
	dfs(1,1,0);
	for(int i = 1; i<=q; i++)
		if(ans[i]) cout <<"Yes"<<endl;
	     else cout <<"No"<<endl;
	return 0;
}