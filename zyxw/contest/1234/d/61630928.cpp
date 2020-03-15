#include<bits/stdc++.h>
#define mx 100007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int tree[4 * mx];
void update(int node, int b, int e, int x, int y,int val) {
    if(e < x || b > y) return;
    if(b >= x && e <= y) {
        tree[node] = val;
        return;
    }
    int mid = (b + e) / 2, lson = 2 * node, rson = lson + 1;
    update(lson, b, mid, x, y, val);
    update(rson, mid + 1, e, x, y, val);
    tree[node] = tree[lson] | tree[rson];
}
int query(int node, int b, int e, int x, int y) {
    if(e < x || b > y) return 0;
    if(b >= x && e <= y) {
        return tree[node];
    }
    int mid = (b + e) / 2, lson = 2 * node, rson = lson + 1;
    return query(lson, b, mid, x, y) | query(rson, mid + 1, e, x, y);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    int n = str.length();
    for(int i = 1; i <= n; i++) {
        int b = str[i - 1] - 'a' + 1;
        update(1,1,n,i,i,(1 << b));
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int pos;
            char ch;
            cin >> pos >> ch;
            int b = ch - 'a' + 1;
            update(1,1,n,pos,pos,(1 << b));
        }
        else {  
            int l, r;
            cin >> l >> r;
            int q = query(1,1,n,l,r);
            cout << __builtin_popcount(q) << endl;
        }
    }
    return 0;
}
