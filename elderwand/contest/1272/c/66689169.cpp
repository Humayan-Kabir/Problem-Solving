#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
using namespace std;
typedef long long int LL;
string str;
int flag[mx];
int main() { 
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cin >> str;
    for(int i = 0; i < k; i++) {
        char ch;
        cin >> ch;
        flag[ch - 'a'] = 1;
    }
    LL ans = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(flag[str[i] - 'a'] == 1) {
            cnt++;
        } else {
            ans += ((cnt * (cnt + 1)) / 2);
            cnt = 0;
        }
    }
    ans += ((cnt * (cnt + 1)) / 2);
    cout << ans << endl;
    return 0;
}