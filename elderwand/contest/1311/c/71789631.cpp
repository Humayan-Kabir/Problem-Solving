#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int cnt[mx][30], a[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string str;
        cin >> str;
        for(int i = 1; i <= m; i++) {
            cin >> a[i];
        } 
        a[m + 1] = n;
        for(int i = 1; i <= n; i++) {
            int id = str[i - 1] - 'a';
            for(int j = 0; j < 26; j++) {
                cnt[i][j] = cnt[i - 1][j] + (j == id);
            }
        }
        LL ans[26] = {0};
        for(int i = 1; i <= m + 1; i++) {
            for(int j = 0; j < 26; j++) {
                ans[j] += cnt[a[i]][j];
            }
        }

        for(int i = 0; i < 26; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;

    }
    return 0;
}