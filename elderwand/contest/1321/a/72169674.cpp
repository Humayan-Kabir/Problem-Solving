#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int a[mx], b[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int cnt = 0, sum = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] && !b[i]) {
            cnt++;
        }
        if(!a[i] && b[i]) {
            sum++;
        }
    }
    if(cnt == 0) {
        cout << -1 << endl;
    } else {
        cout << (sum + cnt - 1) / cnt << endl;
    }
    return 0;

}