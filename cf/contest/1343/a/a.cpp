/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-04-21 20:35:01
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 2; (1 << i) - 1 <= n; i++) {
            int x = (1 << i) - 1;
            if(n % x == 0) {
                cout << n / x << endl;
                break;
            }
        }
    }

    return 0;
}