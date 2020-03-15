#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int moves(int rem, int a, int b, int player = 0) {
    if(rem == 0) {
        return (b + a - 1) / a;
    } else {
        int res = (rem + a - 1) / a;
        return res - 1;
    }
}
vector<int> vt;
int main() {
    ios_base::sync_with_stdio(false);
     int n, a, b, k;
        cin >> n >> a >> b >> k;
        for(int i = 1; i <= n; i++) {
            int num; cin >> num;
            vt.push_back(moves(num % (a + b), a, b));
        }
        sort(vt.begin(), vt.end());
        int ans = 0, t = 0;
        for(int i = 0; i < vt.size(); i++) {
            if(t + vt[i] > k) break;
            t += vt[i];
            ans++;
        }
        cout << ans << endl;
    return 0;
}