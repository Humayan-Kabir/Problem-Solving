/*input
9 5
aAAaBBccD
1 4 a
5 6 c
2 3 B
4 4 D
2 3 A
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
int tree[4*mx];
string str;
void build(int node,int l,int r)
{
	if(l == r) 
	{
		tree[node] = 1; return;
	}
	int lson = 2*node , rson = lson + 1, mid = (l + r)/2;
	build(lson,l,mid); build(rson,mid + 1, r);
	tree[node] = tree[lson] + tree[rson];
}
void update(int node,int l,int r, int x,int y)
{
	if(l > y || r < x) return;
	if(l >= x && r <= y)
	{
		tree[node] = 0;
		return;
	}
	int lson = 2*node, rson = lson + 1, mid = (l + r) / 2;
	update(lson,l,mid,x,y); update(rson,mid + 1,r,x,y);
	tree[node] = tree[lson] + tree[rson];
}
int query(int node,int l,int r,int val)
{
	if(l == r) return l;
	int lson = 2*node, rson = lson + 1, mid = (l + r) / 2;
	if(tree[lson]>=val) return query(lson,l,mid,val);
	return query(rson,mid+1,r,val - tree[lson]);
}
int main(int argc, char const *argv[])
{
	int n,q;
	cin >> n >> q;
	cin >> str;
	set<int>s[200];
	for(int i = 0; i<str.length(); i++)
	{
		s[str[i]].insert(i+1);
	}	
	build(1,1,n);
	while(q--)
	{
		int l,r; char ch;
		cin >> l >> r >> ch;
		l = query(1,1,n,l);
		r = query(1,1,n,r);
		char id = ch;
		auto it = s[id].upper_bound(l-1);
	    while(it != s[id].end() && *it <= r)
	    {
            auto it2 = it;
            update(1, 1, n, *it2, *it2);
            it++;
            s[id].erase(it2);
        }
	}
	for(int i = 1; i<=tree[1]; i++)
	{
		int l = query(1,1,n,i);
		cout << str[l-1];
	}
	cout << endl;
	return 0;
}