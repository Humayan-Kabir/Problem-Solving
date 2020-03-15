#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL v[mx], t[mx];
vector<pair<LL,LL>> vt;
multiset<pair<LL,LL>> myset; /// T-V
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for(int i = 1; i <= n; i++) {
        vt.push_back({v[i], t[i]});
    }
    sort(vt.begin(), vt.end());
    vt.push_back({INT_MAX, INT_MAX});
    LL ans = 0, currentPosition;
    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            myset.insert({vt[i].second * -1, vt[i].first});
            continue;
        } else if(vt[i].first == vt[i - 1].first) {
            myset.insert({vt[i].second * -1, vt[i].first});
        } else {
            if(vt[i].first != vt[i - 1].first) {
                currentPosition = vt[i - 1].first;
                while(currentPosition < vt[i].first && !myset.empty()) {
                    LL T = myset.begin()->first * -1, V = myset.begin()->second;
                    ans += (currentPosition - V) * T;
                    myset.erase(myset.find({T * -1, V}));
                    // cout << T << " tv " << V << endl;
                    // cout << currentPosition << " p " << endl;
                    // cout << ans << " ans " << endl;
                    currentPosition++;
                }
                myset.insert({vt[i].second * -1, vt[i].first});
            }
        }
    }
    cout << ans << endl;
    return 0;
}