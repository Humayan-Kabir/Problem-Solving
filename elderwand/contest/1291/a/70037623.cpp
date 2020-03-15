#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int len, flag = 0;
        cin >> len;
        string str;
        cin >> str;
        for(int i = 0; i < len && !flag; i++) {
            for(int j = i + 1; j < len; j++) {
                int total = str[i] - '0' + str[j] - '0';
                if(total % 2 == 0 && (str[j] - '0') % 2 == 1) {
                    flag = 1;
                    cout << str[i] << str[j] << endl;
                    break;
                }
            }
        }
        if(!flag) {
            cout << -1 << endl;
        }
    }
    return 0;
}