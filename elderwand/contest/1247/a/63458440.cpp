#include<bits/stdc++.h>
#define mod 1000000007
#define mx 3000007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
int ara[mx], tree[mx], pre[mx], vis[mx], Timer = 0;
int main() {
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    if(a == b) {
        a = a * 100 + 12;
        b = a + 1;
        cout << a << " " << b << endl;
        return 0;
    }
    if(a == 9 && b == 1) {
        cout << 999 << ' ' << 1000 << endl;
        return 0;
    }
    if(a > b || (b - a) >= 2) {
        cout << -1 << endl;
        return 0;
    }
    a = a * 100 + 99;
    cout << a << " " << a + 1 << endl;
    return 0;
}