#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
LL ara[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        LL cur = INT_MIN;
        multiset<LL> myset;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            ara[i] = ara[i - 1] + num;
            if(i == 1) {
                cur = max(cur, ara[i]);
            } 
            else if(i == n) {    
                LL res = ara[i] - (*myset.begin());
                cur = max(cur, res);
            }  else {
                LL res = ara[i] - (*myset.begin());
                cur = max(cur, max(res, ara[i]));
            }  
            myset.insert(ara[i]);
        }
        //cout << " " << ara[n] << " " << cur << endl;
        if(cur >= ara[n]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
    return 0;
}