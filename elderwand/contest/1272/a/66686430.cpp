#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
using namespace std;
typedef long long int LL;
int main() { 
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        LL a, b, c;
        vector<LL> vt;
        for(int i = 0; i < 3; i++) {
            int num;
            cin >> num;
            vt.push_back(num);
        }
        sort(vt.begin(), vt.end());
        if(vt[0] == vt[1] && vt[1] == vt[2]) {
            cout << 0 << endl;
            continue;
        }
        if(vt[0] == vt[1]) {
            vt[0]++; vt[1]++;
            if(vt[2] > vt[1]) vt[2]--;
            LL ans = abs(vt[0] - vt[1]) + abs(vt[0] - vt[2]) + abs(vt[1] - vt[2]);
            cout << ans << endl;
            continue;
        }
        if(vt[1] == vt[2]) {
            vt[1]--; vt[2]--;
            if(vt[0] < vt[1]) vt[0]++;
            LL ans = abs(vt[0] - vt[1]) + abs(vt[0] - vt[2]) + abs(vt[1] - vt[2]);
            cout << ans << endl;
            continue;
        }
        vt[0]++; vt[2]--;
        LL ans = abs(vt[0] - vt[1]) + abs(vt[0] - vt[2]) + abs(vt[1] - vt[2]);
        cout << ans << endl;
    }   
    return 0;
}