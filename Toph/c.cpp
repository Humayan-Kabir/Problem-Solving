#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<int> vt(n);
        for(auto &it : vt) cin >> it;
        sort(vt.begin(), vt.begin() + x);
        sort(vt.begin() + x, vt.end());
        int left = 0, ans = max(x, n - x);
        for(int i = x; i < n; i++) {
            while(left < x && vt[left] <= vt[i]) {
                left++;
            }
            ans = max(ans, left + (n - i));
        }
        cout << ans << endl;
    }
    return 0;
}