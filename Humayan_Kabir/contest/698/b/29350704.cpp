#include<bits/stdc++.h>
using namespace std;
 
struct DisjointSet{
	int n;
	vector<int> parent, rank;
	DisjointSet(int n) : n(n), parent(n), rank(n){
		for(int i = 0; i<n; i++)
			parent[i] = i;
	}
	int rootof(int x)
	{
		if(parent[x]!=x) parent[x] = rootof(parent[x]);
		return parent[x];
	}
	bool merge(int x, int y)
	{
		int a = rootof(x);
		int b = rootof(y);
		if(a==b) return false;
		if(rank[a]>rank[b]) parent[b] = a;
		else if(rank[a]<rank[b]) parent[a] = b;
		else{
			rank[a]++;
			parent[b] = a;
		}
		return true;
	}
};
 
int main()
{
	int n;
	scanf("%d", &n);
	int ara[n+1];
	DisjointSet X(n+1);
	vector< pair<int, int> > vt;
	for(int i = 1; i<=n; i++){
		scanf("%d", &ara[i]);
		if(X.merge(i, ara[i]) == false){
			vt.push_back({i, ara[i]});
		}
	}
	int equal = 0;
	for(int i = 0; i<vt.size(); i++)
	{
		if(vt[i].first == vt[i].second) equal = i;
	}
	int ans = vt.size()-1;
 
	if(vt[equal].first != vt[equal].second) ara[vt[equal].first] = vt[equal].first, ans++;
	for(int i = 0; i<vt.size(); i++)
		ara[vt[i].first] = vt[equal].first;
	printf("%d\n", ans);
	for(int i = 1; i<=n; i++)
		printf("%d ", ara[i]);
	return 0;
}
