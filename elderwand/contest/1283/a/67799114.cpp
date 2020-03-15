#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int h, m;
        cin >> h >> m;
        int res = (24 - h - 1) * 60 + 60 - m;
        cout << res << endl;
    }
    
    return 0;
}