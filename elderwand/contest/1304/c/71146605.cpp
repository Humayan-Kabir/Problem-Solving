#include<bits/stdc++.h>
#define mx 300007
#define piii pair<int,pair<int,int>>
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<piii> vt;
        vt.push_back({0,{m, m}});
        for(int i = 1; i <= n; i++) {
            int t, li, hi;
            cin >> t >> li >> hi;
            vt.push_back({t, {li, hi}});
        }
        int flag = 1;
        for(int i = 1; i <= n; i++) {
            int l = vt[i - 1].second.first - abs(vt[i - 1].first - vt[i].first), r = vt[i - 1].second.second + abs(vt[i - 1].first - vt[i].first);
            int x = vt[i].second.first, y = vt[i].second.second;
            if(x > r || y < l) {
                flag = 0; break;
            } 
            vt[i].second.first = max(x, l);
            vt[i].second.second = min(y, r);
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}