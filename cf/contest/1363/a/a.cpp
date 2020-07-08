/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-31 20:37:28
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int odd = 0, even = 0;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            if(num & 1) odd++;
            else even++;
        }
        int flag = 0;
        for(int i = 1; i <= odd; i += 2) {
            if(i > x) break;
            int need = x - i;
            if(even >= need) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}