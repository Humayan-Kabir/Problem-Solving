#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string a, b, c;
        cin >> a >> b >> c;
        int flga = 1;
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == c[i] || b[i] == c[i]) continue;
            flga = 0;
        }
        if(flga) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}