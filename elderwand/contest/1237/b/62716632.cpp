#include<bits/stdc++.h>
#define mx 100007
using namespace std;
int a[mx], b[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        b[num] = i;
    }
    int ans = 0, res = 0;
    for(int i = 1; i <= n; i++) {
        res = max(res, b[a[i]]);
        if(res > b[a[i]]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}