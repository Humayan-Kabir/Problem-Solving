/*input
8
1
1
1
1
3
3
3
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
int leaf[mx];
int parent[mx];
void dfs(int u,int par)
{
	parent[u] = par;
	int flag = 0;
	for(int v : graph[u])
	{
		if(v != par)
		{
			flag = 1;
			dfs(v,u);
		}
	}
	if(flag == 0) 
	{
		leaf[u] = 1;
	}
}
int main(int argc, char const *argv[])
{ 
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i<n; i++)
	{
		int v;
		cin >> v;
		graph[i+1].push_back(v);
		graph[v].push_back(i+1);
	}
	dfs(1,1);
    for(int i = 1; i<=n; i++)
    {
    	int cnt = 0;
    	if(leaf[i]) continue;
    	for(int v : graph[i])
    	{
    		if(v == parent[i]) continue;
    		cnt+=leaf[v];
    	}
    	if(cnt<3) {
    		cout << "No"<< endl;
    		return 0;
    	} 
    }
	cout <<"Yes"<< endl;
	return 0;
}