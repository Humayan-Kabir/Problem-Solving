#include<bits/stdc++.h>
#define mx 100007
#define tuple pair<pair<int,int>, pair<int,int>> 
using namespace std;
typedef long long int LL;
vector<tuple> vt1;
vector<tuple> vt2;
priority_queue<pair<int,int> > pq;
pair<int,int> tree[4 * mx];
vector<tuple> vt;
void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = vt[b - 1].second;
        return;
    }
    int lson = 2 * node, rson = lson + 1, mid = (b + e) / 2;
    build(lson, b, mid); build(rson, mid + 1, e);
    tree[node].first = max(tree[lson].first, tree[rson].first);
    tree[node].second = min(tree[lson].second, tree[rson].second);
}
void update(int node, int b, int e, int x, int y, int val, int flag) {
    if(b > y || e < x) return;
    if(b >= x && e <= y) {
        tree[node] = {INT_MIN, INT_MAX};
        return;
    }
    int lson = 2 * node, rson = lson + 1, mid = (b + e) / 2;
    update(lson, b, mid, x, y, val, flag);
    update(rson, mid + 1, e, x, y, val, flag);
    tree[node].first = max(tree[lson].first, tree[rson].first);
    tree[node].second = min(tree[lson].second, tree[rson].second);
}
int query(int node, int b, int e, int x, int y, int flag) {
    if(b > y || e < x) {
        if(flag == 1) {
            return INT_MIN;
        } else {
            return INT_MAX;
        }
    }
    if(b >= x && e <= y) {
        if(flag == 1) {
            return tree[node].first;
        } else {
            return tree[node].second;
        }
    }
    int lson = 2 * node, rson = lson + 1, mid = (b + e) / 2;
    int left = query(lson, b, mid, x, y, flag), right = query(rson, mid + 1, e, x, y, flag);
    if(flag) return max(left, right);
    else return min(left, right);
}
bool check(int n) {
    sort(vt.begin(), vt.end());
    while(!pq.empty()) {
        pq.pop();
    }
    build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        while(!pq.empty() && pq.top().first < vt[i - 1].first.first) {
            int id = pq.top().second;
            pq.pop();
            update(1, 1, n, id, id, INT_MAX, 0);
        }
        pq.push({vt[i - 1].first.second, i});
        int low = i, high = n, to = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(vt[mid - 1].first.first <= vt[i - 1].first.second) {
                to = max(to, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(query(1, 1, n, 1, to, 1) > vt[i - 1].second.second) return 1;
        if(query(1, 1, n, 1, to, 0) < vt[i - 1].second.first) return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> vt1, vt2;
    for(int i = 1; i <=n; i++) {
        string str;
        cin >> str;
        vt1.push_back(str);
    }
     for(int i = 1; i <=m; i++) {
        string str;
        cin >> str;
        vt2.push_back(str);
    }
    int q;
    cin >> q;
    while ((q--))
    {
        int x;
        cin >> x;
        cout << vt1[x % n == 0 ? n - 1: (x % n) - 1] + vt2[x % m == 0 ? m - 1: (x % m) - 1] << endl;
    }
    
    return 0;
}   