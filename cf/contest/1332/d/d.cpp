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
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k;
    cin >> k;
    int v = k | (1 << 17);
    cout << 3 << " " << 3 << endl;
    cout << v << " " << k << " " << k << endl;
    cout << v - k << " " << v - k << " " << v << endl;
    cout << k << " " << k << " " << k << endl;
    return 0;
}