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
        if((n / 2) & 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            LL total = 0;
            for(int i = 2; i <= n; i += 2) {
                total += i;
                if(i == 2) {
                    cout << i;
                } else {
                    cout << " " << i;
                }
            }
            for(int i = 1; i <= n; i += 2) {
                if(i == n - 1) {
                    cout << " " << total << endl;
                } else {
                    cout << " " << i;
                    total -= i;
                }
            } 
        }
    }

    return 0;
}