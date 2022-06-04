#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int counter = 2;
    string ans = "";
    while(counter--) {
        cout << n % 10 << endl;
        ans += ('0' + n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}