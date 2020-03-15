#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int odd = 0, even = 0;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            if(num & 1) odd++;
            else even++;
        }
        if(odd && even) {
            cout << "YES" << endl;
        } else if(odd == n && (n & 1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }   
    }
    return 0;
}