#include<bits/stdc++.h>
#define mx 200007
#define mod 998244353
using namespace std;
typedef long long int LL;
int ara[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    int n, mxposition, to = -1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        if(ara[i] > to) {
            to = ara[i];
            mxposition = i;
        }
    }
    int flag = 1;
    for(int j = 2; j <= mxposition; j++) {
        if(ara[j] <= ara[j - 1]) flag = 0;
    }
    for(int j = mxposition + 1; j <= n; j++) {
        if(ara[j] >= ara[j - 1]) flag = 0;
    }
    if(flag) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}