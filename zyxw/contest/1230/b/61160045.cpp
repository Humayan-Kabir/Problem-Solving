#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int dp[mx], cnt[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    if(k == 0) {
        cout << str << endl;
        return 0;
    }
    if(n == 1) {
        cout << "0" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if(str[i] == '1') {
                cout << "1";
                continue;
            }
            if(k > 0) {
                cout << "1";
                k--;
            }
        }
        else {
            if(k > 0 && str[i] != '0') {
                cout << "0";
                k--;
            }
            else {
                cout << str[i];
            }
        }
    }
    cout << endl;
    return 0;
}
