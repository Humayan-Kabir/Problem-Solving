#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int cnt[mx], cumu[mx], numTwo[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    LL a , b, c, d;
    cin >> a >> b >> c >> d;
    if(c == 0) {
        if(a == d) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    else {
        if (a == d && a > 0)
        {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}