#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
multiset<int> myset;
int main() {
    ios_base::sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while(t--) {
        
    // }
    int q, mod;
    cin >> q >> mod;
    myset.clear();
    int ans = 0;
    for(int i = 1; i <= q; i++) {
        int num;
        cin >> num;
        myset.insert(num % mod);
        while(!myset.empty()) {
            if(myset.find(ans % mod) == myset.end()) break;
            myset.erase(myset.find(ans % mod)); ans++;
        }
        cout << ans << endl;
    }
    return 0;
}