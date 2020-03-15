#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define mx 300007
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false); 
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int flag = 0, len = str.length();
        for(int i = 0; i < len - 1; i++) {
            if(str[i] == '?') continue;
            if(str[i] == str[i + 1]) flag = 1;
        }
        if(flag) {
            cout << -1 << endl;
        } else {
            for(int i = 0; i < len; i++) {
                if(str[i] == '?') {
                    int ara[4] = {0};
                    if(i > 0) ara[str[i - 1] - 'a'] = 1;
                    if(i < len - 1) ara[str[i + 1] - 'a'] = 1;
                    for(int j = 0; j < 3; j++) {
                        if(ara[j] == 0) {
                            char ch = 'a' + j;
                            str[i] = ch;
                            break;
                        }
                    }
                    cout << str[i]; 
                } else {
                    cout << str[i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
