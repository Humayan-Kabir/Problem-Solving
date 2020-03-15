/*input
6 2
1 1 1 2 2 2
5
1 6
4 3
1 1
2 6
2 6
*/
#include <bits/stdc++.h>
#define mx 100007
#define LOG 20
using namespace std;
int nodeNo = 0;
deque <int> dq[mx];
struct Node
{
	int l, r, sum;
	Node(){}
}tree[mx * LOG];
void update(int prevNode,int &curNode,int b,int e,int i,int val)
{
	curNode = ++nodeNo;
	int mid = (b + e) / 2;
	if(b == e)
	{
		tree[curNode].sum = tree[prevNode].sum + val;
		return;
	}
	if(i<=mid)
	{
		update(tree[prevNode].l,tree[curNode].l,b,mid,i,val);
		tree[curNode].r = tree[prevNode].r;
	}
	else
	{
		update(tree[prevNode].r,tree[curNode].r,mid + 1,e,i,val);
		tree[curNode].l = tree[prevNode].l;
	}
	tree[curNode].sum = tree[tree[curNode].l].sum + tree[tree[curNode].r].sum;
}
int query(int node,int b,int e,int i,int j)
{
	if(b > j || e < i) return 0;
	if(b>=i && e<=j) return tree[node].sum;
	int mid = (b + e) / 2;
	return query(tree[node].l,b,mid,i,j) + query(tree[node].r,mid + 1,e,i,j);
}
int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d",&n,&k);
	int previous[mx];
	for(int i = 0; i<n; i++)
	{
		int height;
		scanf("%d",&height);
		if(dq[height].size() == k)
		{
			previous[i] = dq[height].front();
			dq[height].pop_front();
			dq[height].push_back(i + 1);
		}
		else
		{
			previous[i] = 0;
			dq[height].push_back(i + 1);
		}
	}
	int root[mx];
	root[0] = 0;
	for(int i = 0; i<n; i++)
	{
		update(root[i],root[i+1],0,n,previous[i],1);
	}
	int q, last = 0;
	scanf("%d",&q);
	while(q--)
	{
		int l, r;
		scanf("%d %d",&l,&r);
		l = (l + last) % n + 1;
		r = (r + last) % n + 1;
		if(l > r) swap(l,r);
		last = query(root[r],0,n,0,l - 1) - query(root[l - 1],0,n,0,l - 1);
		printf("%d\n",last);
	}
	return 0;
}