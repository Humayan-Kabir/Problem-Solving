/*input
5 4
abaca
1 2
1 3
3 4
4 5
*/
#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
int ara[mx][30];
int mxara[mx][30];
string str;
int vis[mx];
vector<int> vv;
void dfs(int u)
{
	vis[u] = 1;
	for(int v : graph[u])
		if(!vis[v])
			dfs(v);
	vv.push_back(u);	
}
int mark[mx];
int nowmax, globalmx = 1;
void rec(int u)
{
	if(mark[u] == 1) return;
	mark[u] = 1;	
	for(int v : graph[u])
	{
		if(!mark[v])
		{
			rec(v);
			for(int i = 0; i<26; i++)
			{
				mxara[u][i] = max(mxara[u][i],ara[u][i] + mxara[v][i]);
				nowmax = max(nowmax,mxara[u][i]);
			}
		}
		else 
		{
			for(int i = 0; i<26; i++)
			{
				mxara[u][i] = max(mxara[u][i],ara[u][i] + mxara[v][i]);
				nowmax = max(nowmax,mxara[u][i]);
			}
		}
	}
}
bool isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
        for(int u : graph[v])
        {
            if ( !visited[u] && isCyclicUtil(u, visited, recStack) )
                return true;
            else if (recStack[u])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

bool isCyclic(int V)
{
   
    bool *visited = new bool[V + 2];
    bool *recStack = new bool[V + 2];
    for(int i = 0; i <= V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 1; i <= V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
    return false;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	cin >> str;
	int foo = 0;
	for(int i = 1; i<=m; i++)
	{
		int u,v;
		cin >> u >> v;
		if(u == v)
		{
			foo = 1;
			graph[u].push_back(v);
		}
		else 
		{
			graph[u].push_back(v);
		}
	}
	if(foo == 0)
    foo = isCyclic(n);
	if(foo)
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 1; i<=n; i++)
	{
		int id = str[i - 1] - 'a';
		ara[i][id]++;
		mxara[i][id] = ara[i][id];
	}
	for(int i = 1; i<=n; i++)
	{
		if(vis[i] == 0)
			dfs(i);
	}
	reverse(vv.begin(), vv.end());
	for(int i = 0; i<vv.size(); i++)
	{
		if(mark[vv[i]] == 0)
		{
			rec(vv[i]);
			globalmx = max(globalmx,nowmax);
			nowmax = 0;
		}
	}
	printf("%d\n", globalmx);
	return 0;
}