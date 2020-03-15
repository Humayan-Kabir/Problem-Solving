#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r, sum = 0;
    node() {}
};

namespace persistentSeg {
    const int LOG = 20, mx = 200007;
    struct node {
        int l, r, sum = 0;
        node() {}
    } tree[LOG * mx];
    int availNode = 0, ara[mx], root[mx], previous[mx];
    void update(int prevnode, int &curnode, int b, int e, int x, int val) {
        curnode = ++availNode;
        if(e < x || b > x || b > e) return;
        if(b == e) {
            tree[curnode].sum = tree[prevnode].sum + val;
            return;
        }
        int mid = (b + e) / 2;
        if(x <= mid) {
            update(tree[prevnode].l, tree[curnode].l, b, mid, x, val);
            tree[curnode].r = tree[prevnode].r;
        }
        else {
            update(tree[prevnode].r, tree[curnode].r, mid + 1, e, x, val);
            tree[curnode].l = tree[prevnode].l;
        }
        tree[curnode].sum = tree[tree[curnode].l].sum + tree[tree[curnode].r].sum;
    }
    int query(int curnode, int b, int e, int k) {
        int mid = (b + e) / 2;
        if(b == e) {
            return b;
        }
        if(tree[tree[curnode].l].sum > k){
            return query(tree[curnode].l, b, mid, k);
        }
        else {
            return query(tree[curnode].r, mid + 1, e, k - tree[tree[curnode].l].sum);
        }
    }
    void solve() {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        for(int i = n; i >= 1; i--) {
            if(previous[ara[i]]) {
                update(root[i + 1], root[i], 1, n + 1, previous[ara[i]], -1);
                previous[ara[i]] = i;
                update(root[i], root[i], 1, n + 1, previous[ara[i]], 1);
            }
            else {
                previous[ara[i]] = i;
                update(root[i + 1], root[i], 1, n + 1, previous[ara[i]], 1);
            }
        }
        for(int i = 1; i <= n; i++) {
            int curPos = 1, ans = 0;
            while(curPos <= n) {
                curPos = query(root[curPos], 1, n + 1, i);
                ans++;
            }
            cout << ans << endl;
        }
    }

}
int main(int argc, char const *argv[])
{
    persistentSeg::solve();
    return 0;
}
