/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-06-20 20:35:43
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 2000007
using namespace std;
typedef long long int LL;
int divisor[mx];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 1; i <= 1000000; i++) {
        for(int j = i + i; j <= 1000000; j+=i) {
            divisor[j] = max(divisor[j], i);
        }
    }
    for(int i = 1; i <= 1000000; i++) {
        divisor[i] = max(divisor[i - 1], divisor[i]);
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << divisor[n] << endl;
    }
    return 0;
}