#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
LL grid[200][200], cnt[200];
int main() {
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    int len = str.length();
    LL ans = 0;
    for(int i = 0; i < len; i++) {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            grid[ch][str[i]] += cnt[ch];
        }
        cnt[str[i]]++;
        ans = max(ans, cnt[str[i]]);
    }
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            ans = max(ans, grid[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}