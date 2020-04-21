/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-03-31 19:35:02
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int counter[mx][26];
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if(x > x2 || x < x1 || y > y2 || y < y1) {
            cout << "NO" << endl;
            continue;
        }
        x += (-a + b);
        y += (-c + d);
        if(x > x2 || x < x1 || y > y2 || y < y1) {
            cout << "NO" << endl;
            continue;
        }
        if(x1 == x2 && max(a, b) > 0) {
            cout << "NO" << endl;
            continue;
        } 
        if(y1 == y2 && max(c, d) > 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}