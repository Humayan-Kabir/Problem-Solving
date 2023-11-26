#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int total = 0;
        int cnt = 0;
        int found = false;
        for(int i = 0; i < n; i++) {
            if (s[i] == '.') {
                cnt++;
            } else {
                found |= (cnt >= 3);
                total += cnt;
                cnt = 0;
            }
        }
        if (cnt > 0) {
            found |= (cnt >= 3);
            total += cnt;
        }
        if (found) cout << min(total, 2) << endl;
        else cout << total << endl;
    }   
    return 0;
}