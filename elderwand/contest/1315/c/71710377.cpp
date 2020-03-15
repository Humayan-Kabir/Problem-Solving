#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int ara[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t; 
    while(t--) {
        set<int> myset;
        int n;
        cin >> n;
        for(int i = 1; i <= 2 * n; i++) {
            myset.insert(i);
        }
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            myset.erase(myset.find(ara[i]));
        }
        vector<int> ans;
        int flag = 0;
        for(int i = 1; i <= n; i++) {
            ans.push_back(ara[i]);
            auto it = myset.upper_bound(ara[i]);
            if(it != myset.end()) {
                int val = *(it);
                ans.push_back(val);
                myset.erase(myset.find(val));
            } else {
                flag = 1;
            }
        }
        if(flag) {
            cout << -1 << endl;
        } else {
            for(int v : ans) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    return 0;
}