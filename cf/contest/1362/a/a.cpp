/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-11 09:20:50
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
        LL a, b;
        cin >> a >> b;
        int counter = 0;
        if(a > b) swap(a, b);
        while(b % 8 == 0 && (b >> 3) >= a) b = b >> 3, counter++;
        while(b % 4 == 0 && (b >> 2) >= a) b = b >> 2, counter++;
        while(b % 2 == 0 && (b >> 1) >= a) b = b >> 1, counter++;
        if(a == b) {
            cout << counter << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}