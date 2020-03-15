/*input
4 6
1 2 999999001
1 3 999999003
1 4 999999009
2 3 999999027
2 4 999999243
3 4 999999729
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
struct node
{
	int u,v,w;
	node(int u,int v,int w)
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
vector< node > graph,Graph2;
vector< pair<int,int> > Edge[mx];
LL n, m, MST = 0;
struct DisjointSet
{
   int node;
   vector<int> parents,rank;
   DisjointSet(int node)
   {
       this->node = node;
       for(int i = 0; i <= node; i++)
       {
           parents.push_back(i);
           rank.push_back(0);
       }
   }
   int Find(int n)
   {
       if(parents[n] == n) return parents[n];
       return parents[n] = Find(parents[n]);
   }
   void Union(int a,int b)
   {
       int u = Find(a);
       int v = Find(b);
       if(u != v)
       {
           if(rank[u] == rank[v])
           {
               rank[u]++;
               parents[v] = u;
           }
           else if(rank[u] > rank[v])
           {
               parents[v] = u;
           }
           else
           {
               parents[u] = v;
           }
       }
   }
};
int sparse_table[mx][19], level[mx],Min_table[mx][19];
pair<int,int> parents[mx];
map< pair<int,int>, int > mymap;
void dfs(int u,int par,int lev,int w)
{
	parents[u] = {par,w};
	level[u] = lev;
	for(auto v : Edge[u]) 
		if(par != v.first)
			dfs(v.first,u,lev + 1,v.second);

}
void Make_Table()
{
	memset(sparse_table,-1,sizeof sparse_table);
	for(int i = 1; i<=n; i++)
		for(int j = 0; j<=18; j++)
			sparse_table[i][0] = parents[i].first, Min_table[i][0] = parents[i].second;
    
    for(int j = 1; j<=18; j++)
    {
    	for(int i = 1; i<=n; i++)
    	{
    		int u = sparse_table[i][j-1];
    		if(u == -1) continue;
    		Min_table[i][j] = max(Min_table[i][j-1],Min_table[u][j-1]);
    		sparse_table[i][j] = sparse_table[u][j-1];
    	}
    }
}
int query(int p,int q)
{
	if(level[p] < level[q]) swap(p,q);
	int MAX = 0;
	for(int j = 18; j>=0; j--)
	{
		if(level[p] - (1<<j) >= level[q])
		{
			MAX = max(MAX,Min_table[p][j]);
			p = sparse_table[p][j];
		}
	}
	if(p == q) return MAX;
	for(int j = 18; j>=0; j--)
	{
		if(sparse_table[p][j] != -1 && sparse_table[p][j] != sparse_table[q][j])
		{
			MAX = max(MAX,max(Min_table[p][j],Min_table[q][j]));
			p = sparse_table[p][j]; q = sparse_table[q][j];
		}
	}

	MAX = max(MAX,max(Min_table[p][0],Min_table[q][0]));
	return MAX;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i<=m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back(node(u,v,w));
	}
	Graph2 = graph;
	sort(graph.begin(), graph.end(),[](const node a, const node b){ return a.w < b.w;});
	DisjointSet D(mx);
	int cnt = 0;
	for(int i = 0; i<graph.size(); i++)
	{
		if(D.Find(graph[i].u) != D.Find(graph[i].v))
		{
			MST+=graph[i].w;
			D.Union(graph[i].u,graph[i].v);
			Edge[graph[i].u].push_back({graph[i].v, graph[i].w});
			Edge[graph[i].v].push_back({graph[i].u,graph[i].w});
			mymap[{graph[i].u,graph[i].v}] = 1;
 			cnt++;
		}
	}
	dfs(1,-1,0,0);
	Make_Table();
	for(int i = 0; i<Graph2.size(); i++)
	{
		int u = Graph2[i].u, v = Graph2[i].v;
		if(mymap.find({u,v}) != mymap.end())
		{
			cout << MST << endl;
		}
		else
		{
			cout << MST - query(u,v) + Graph2[i].w << endl;
 		}
	}
	return 0;
}