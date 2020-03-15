#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int a[mx], b[mx];
map<int,LL> maping;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    for(int i = n; i >= 1; i--) {
       maping[i - a[i]] += a[i];
    }
    for(auto it : maping) {
        ans = max(ans, 1LL * it.second);
    }
    cout << ans << endl;
    return 0;

}