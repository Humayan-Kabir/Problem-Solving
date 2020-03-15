#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
namespace segtree {
    int n, ara[mx], tree[4 * mx];
    void build(int node, int b, int e) {
        if(b == e) {
            tree[node] = ara[b];
            return;
        }
        int mid = (b + e) / 2, lson = node << 1, rson = lson | 1;
        build(lson, b, mid); build(rson, mid + 1, e);
        tree[node] = max(tree[lson], tree[rson]);
    }
    int query(int node, int b, int e, int x, int y) {
        if(e < x || b > y) return 0;
        if(b >= x && e <= y) return tree[node];
        int mid = (b + e) / 2, lson = node << 1, rson = lson | 1;
        return max(query(lson, b, mid, x, y), query(rson, mid + 1, e, x, y));
    }
    void solve() {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &ara[i]);
            ara[n + i] = ara[n + n + i] = ara[i];
        }
        build(1, 1, n + n + n);
        for(int i = 1; i <= n + n + n; i++) {
            int low = 0, high = i, ans = i;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(query(1, 1, n + n + n, mid, i) <= (ara[i] * 2)) {
                    ans = min(ans, mid);
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            ara[i] = ans;
        }
        build(1, 1, n + n + n);
        for(int i = 1; i <= n; i++) {
            int low = i, high = n + n + n, ans = i;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(query(1, 1, n + n + n, i, mid) <= i) {
                    ans = max(ans, mid);
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            ans = ans - i + 1;
            ans = (ans < 2 * n) ? ans : -1;
            printf("%d\n", ans);
        }
        puts("");
    }
};
int main() {
    segtree::solve();
    return 0;
}