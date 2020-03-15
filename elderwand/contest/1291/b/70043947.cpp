#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int ara[mx], prefix[mx], suffix[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i]; prefix[i] = suffix[i] = 0;
        }
        for(int i = n; i >= 1; i--) {
            if(i == n) {
                suffix[i] = 1;
            } else {
                suffix[i] = suffix[i + 1] & (ara[i] >= (n - i));
            }
        }
        int flag = 0;
        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                prefix[i] = 1;
            } else {
                prefix[i] = prefix[i - 1] & (ara[i] >= (i - 1));
            }
            if(prefix[i] && suffix[i]) flag = 1;
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}