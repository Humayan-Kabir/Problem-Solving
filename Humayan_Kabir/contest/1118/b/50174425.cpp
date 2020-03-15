#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL ara[mx];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    LL odd = 0, even = 0;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        if(i & 1) odd += ara[i];
        else even += ara[i];
    }
    int ans = 0, curOdd = 0, curEven = 0;
    for(int i = 1; i <= n; i++) {
        if(i & 1) odd -= ara[i];
        else even -= ara[i];
        if(i & 1) {
            if(curOdd + even == curEven + odd) {
                ans++;
            }
        }
        else {
            if(curEven + odd == curOdd + even) {
                ans++;
            }
        }
        if(i & 1) curOdd += ara[i];
        else curEven += ara[i];
    }
    cout << ans << endl;
    return 0;
}