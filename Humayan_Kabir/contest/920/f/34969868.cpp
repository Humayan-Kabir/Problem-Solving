/*input
7 6
6 4 1 10 3 2 4
2 1 7
2 4 5
1 3 5
2 4 4
1 5 7
2 1 7
*/
#include <bits/stdc++.h>
#define mx 300007
#define MX 1000000
using namespace std;
typedef long long int LL;
LL ara[mx], divisor[4 * mx], tree[4 * mx], mxTree[4 * mx]; 
void InitiaLization()
{
	for(LL i = 1; i<=MX; i++)
		for(LL j = i; j<=MX; j+=i)
			divisor[j]++;
}
void build(LL node,LL b,LL e)
{
	if(b == e)
	{
		tree[node] = ara[b];
		mxTree[node] = ara[b];
		return;
	}
	LL mid = (b + e) / 2, lson = 2 * node, rson = lson + 1;
	build(lson,b,mid); build(rson,mid + 1, e);
	tree[node] = tree[lson] + tree[rson];
	mxTree[node] = max(mxTree[lson], mxTree[rson]);
}
void update(LL node,LL b,LL e,LL x,LL y)
{
	if(b > y || e < x) return;
	if(mxTree[node]<=2) return;
	if(b == e)
	{
		tree[node] = divisor[tree[node]];
		mxTree[node] = tree[node];
		return;
	}
	LL mid = (b + e) / 2, lson = 2 * node, rson = lson + 1;
	update(lson,b,mid,x,y); update(rson,mid + 1,e,x,y);
	tree[node] = tree[lson] + tree[rson];
	mxTree[node] = max(mxTree[lson], mxTree[rson]);
}
LL query(LL node,LL b,LL e,LL x,LL y)
{
	if(b > y || e < x) return 0;
	if(b>=x && e<=y) return tree[node];
	LL mid = (b + e) / 2, lson = 2 * node, rson = lson + 1;
	return query(lson,b,mid,x,y) + query(rson,mid + 1,e,x,y);

}
int main(int argc, char const *argv[])
{
	InitiaLization();
	LL n, m;
	scanf("%lld %lld",&n,&m);
	for(LL i = 1; i<=n; i++) scanf("%d",ara + i);
	build(1,1,n);
	while(m--)
	{
		LL t, l , r;
		scanf("%lld %lld %lld",&t,&l,&r);
		if(t == 1)
		{
			update(1,1,n,l,r);
		}
		else 
		{
			printf("%lld\n",query(1,1,n,l,r));
		}
	}	
	return 0;
}