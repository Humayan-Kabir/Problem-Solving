#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int test = 1; test <= t; test++) {
        int n, x, y; cin >> n >> x >> y;
        LL total = (n * (n + 1)) / 2;
        LL alanSum = (total * x + (x + y - 1)) / (x + y);
        LL barbaraSum = (total * y + (x + y - 1)) / (x + y);
        if (alanSum + barbaraSum == total) {
            cout << "Case #" << test << ": POSSIBLE" << endl;
            vector<int> ans;
            for(int i = 1; i <= n && alanSum > 0; i++) {
                alanSum -= i;
                ans.push_back(i); 
                if (alanSum < 0) {
                    ans.erase(ans.begin() + abs(alanSum) - 1);   
                    break;
                }
            }
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++) {
                if (i > 0) cout << " ";
                cout << ans[i];
            }
            cout << endl;
        } else {
            cout << "Case #" << test << ": IMPOSSIBLE" << endl;
        }
    }
    return 0;
}