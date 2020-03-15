#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int arr[mx], brr[mx], vis[mx], pos[mx], Timer = 0;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
          cin >> arr[i];
          pos[arr[i]] = i;
        }
        for(int i = 1; i <= m; i++) {
            cin >> brr[i];
        }
        LL ans = 0; Timer++;
        int idx = 0;
        for(int i = 1; i <= m; i++) {
            if(pos[brr[i]] <= idx) {
                ans++; continue;
            }
            idx = pos[brr[i]];
            int cnt = idx - i;
            ans += (2 * cnt + 1);
        }
        cout << ans << endl;
    }
    return 0;
}