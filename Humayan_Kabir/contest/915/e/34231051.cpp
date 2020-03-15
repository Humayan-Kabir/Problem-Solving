/*input
4
6
1 2 1
3 4 1
2 3 2
1 3 2
2 4 1
1 4 2
*/
#include <bits/stdc++.h>
#define mx 19000005
using namespace std;
struct data
{
	int l,r,val; 
	data() {}
}tree[mx];
short int lazy[mx];
int curNode = 1;
inline void propagate(int node,int l,int r)
{
	if(lazy[node] == 0) return;
	if(tree[node].l == 0) tree[node].l = curNode++;
	if(tree[node].r == 0) tree[node].r = curNode++;
	if(l != r) lazy[tree[node].l] = lazy[node], lazy[tree[node].r] = lazy[node];
	tree[node].val = 1 * (r - l + 1) * (lazy[node] == 1 ? 0 : 1);
	lazy[node] = 0;
}
void update(int node,int b,int e,int i,int j,int val)
{
	if(e < i || j < b) {
		if(lazy[node]){
			if(lazy[node] == 1) tree[node].val = 0;
			else tree[node].val = e - b + 1;
		}
		return;
	}
	if(b >= i && e <= j) {
		lazy[node] = val;
		propagate(node, b, e);
		return;
	}
	propagate(node, b, e);
	int mid = (b+e)/2;
	if(tree[node].l == 0) tree[node].l = curNode++;
	if(tree[node].r == 0) tree[node].r = curNode++;
	update(tree[node].l, b, mid, i, j, val);
	update(tree[node].r, mid + 1, e, i, j, val);
	tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int q;
	scanf("%d",&q);
	update(0,1,n,1,n,2);
	for(int i = 1; i<=q; i++)
	{
		int l, r, k;
		scanf("%d %d %d",&l,&r,&k);
		update(0,1,n,l,r,k);
		printf("%d\n",tree[0].val);
	}
	return 0;
}