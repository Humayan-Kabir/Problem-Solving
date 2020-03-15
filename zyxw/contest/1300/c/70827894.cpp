#include<bits/stdc++.h>
using namespace std;
namespace anuHasAfunction {
    void solve() {
        int n;
        cin >> n;
        int ara[n + 1], counter[32] = {0};
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            for(int j = 0; j < 32; j++) {
                if(ara[i] & (1 << j)) {
                    counter[j]++;
                }
            }
        }

        int res = -1, idx;
        for(int i = 1; i <= n; i++) {
            int curmxans = 0;
            for(int j = 0; j < 32; j++) {
                if((ara[i] & (1 << j)) && counter[j] == 1) {
                    curmxans |= (1 << j);
                }
            }
            if(curmxans > res) {
                res = curmxans;
                idx = i;
            }
        }
        cout << ara[idx] << " ";
        for(int i = 1; i <= n; i++) {
            if(i != idx) cout << ara[i] << " ";
            if(i == n) cout << endl;
        }
    }
}
int main() {
    anuHasAfunction::solve();
    return 0;
}