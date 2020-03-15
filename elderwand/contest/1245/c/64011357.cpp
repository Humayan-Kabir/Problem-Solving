#include<bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL fibo[mx];
int main() {
    fibo[1] = 1;
    fibo[2] = 2;
    for(int i = 3; i < mx; i++) {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;
    }
    string str;
    cin >> str;
    LL flag = 1, ans = 1, n = str.length(), cnt = 0;
    for(int i = 0; i < n; i++) {
        int go = i;
        if(str[i] == 'm' || str[i] == 'w') flag = 0;
        if(str[i] == 'u' || str[i] == 'n') {
            while(go < n && str[go] == str[i]) {
                go++;
            }
            ans = ans * fibo[go - i];
            ans = ans % mod;
            i = go - 1;
        }
    }
    cout << ans * flag << endl;
    return 0;
}