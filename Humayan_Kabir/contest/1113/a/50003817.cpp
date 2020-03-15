#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int n, v;
    cin >> n >> v;
    int ans = 0, total = 0;
    for(int i = 1; i < n; i++) {
        if(i == 1) {
            ans += min(v, n - 1);
            total += min(v, n - 1);
        }
        else {
            if(total < n - 1) {
                total++;
                ans += i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}