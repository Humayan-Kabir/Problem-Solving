#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int pre = 0, ans = 0, flag = 0;
        for(int i = 1; i <= str.length(); i++) {
            if(str[i - 1] == '1' && flag == 0) {
                flag = 1; pre = i;
                continue;
            }
            if(str[i - 1] == '1') {
                ans += (i - pre - 1);
                pre = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}