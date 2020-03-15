#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int cnt[30] = {0};
        string a;
        string b;
        cin >> a >> b;
        for(char ch : a) {
            cnt[ch - 'a']++;
        }
        int l = b.length(), m = a.length(), f = 0;
        for(int i = 0; i < l; i++) {
            int ara[30] = {0};
            for(int j = 0; j < 30; j++) ara[j] = cnt[j];
            int now = 0;
            for(int j = i; j < l; j++) {
                if(ara[b[j] - 'a'] > 0) {
                    now++;
                    ara[b[j] - 'a']--;
                }
                else break;
            }
            if(now == m) {
                f = 1;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}