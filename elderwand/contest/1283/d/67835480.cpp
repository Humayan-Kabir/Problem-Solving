#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
struct node {
    LL dist, origin, limit, direction;
    node(LL a, LL b, LL c, LL d) {
        dist = a; origin = b; limit = c; direction = d;
    }
    bool operator < (const node &a) const {
        return dist > a.dist;
    } 
};
priority_queue<node> pq;
vector<int> vt;
vector<LL> res;
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int point;
        cin >> point;
        vt.push_back(point);
    }
    sort(vt.begin(), vt.end());
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            pq.push(node(0, vt[i], INT_MAX, -1));
        }
        if(i == n - 1) {
            pq.push(node(0, vt[i], INT_MAX, 1));
        }
        if(i < n - 1) {
            LL dist = abs(vt[i + 1] - vt[i]) - 1;
            if(dist == 0) continue;
            LL left = (dist + 1) / 2, right = dist - left;
            if(left > 0) {
                LL a, b, c, d;
                a = 0; b = vt[i]; c = left; d = 1;
                pq.push(node(a, b, c, d));
            }
            if(right > 0) {
                pq.push(node(0, vt[i + 1], right, -1));
            }
        }
    }
    LL ans = 0;
    for(int i = 1; i <= m; i++) {
        node it = pq.top();
        pq.pop();
        // cout << it.dist << " "<< it.origin <<" "<< it.limit << " "<< it.direction << endl;
        it.dist++;
        ans += (it.dist);
        res.push_back(it.origin + (it.dist) * it.direction);
        if(it.dist < it.limit) {
            pq.push(it);
        }
    }
    cout << ans << endl;
    for(auto v : res) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}