#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, r;
        cin >> n >> r;
        set<int> s;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            s.insert(num);
        }
        int ans = s.size(), idx = 1;
        for(int x : s) {
            ara[idx] = x;
            idx++;
        }
        LL cur = 1LL*ans;
        for(int i = ans; i >= 1; i--) {
            LL hit = ans - i + 1;
            if(hit * r >= 1LL*ara[i - 1]) {
                cur = min(cur, hit);
            }
        }
        cout << cur << endl;
    }
    return 0;
}