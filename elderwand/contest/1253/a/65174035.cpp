#include<bits/stdc++.h>
#define mx 300007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
int c[mx], d[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        int flag = 1, res, l = 1, r = n;
        for(int i = 1; i <= n; i++) {
            if(c[i] == d[i]) l++;
            else break;
        }
        for(int i = n; i >= 1; i--) {
            if(d[i] == c[i]) r--;
            else break;
        }
        for(int i = l; i <= r; i++) {
            if(i == l) {
                res = d[i] - c[i];
                if(res < 0) flag = 0;
                continue;
            }
            if(d[i] - c[i] != res) flag = 0;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }       
    return 0;
}