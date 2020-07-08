/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-06-20 22:43:35
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 2000007
using namespace std;
typedef long long int LL;
string a, b;
int arr[mx];
set<int> x, y;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    cin >> a >> b;
    for(int i = 0; i < n; i++) {
        if(a[i] == '0' && b[i] == '1') {
            x.insert(i);
        } else if(a[i] == '1' && b[i] == '0') {
            y.insert(i);
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(x.find(i) != x.end()) {
            auto it = x.find(i);
            while(it != x.end()) {
                auto it2 = it++;
                x.erase(it);
                auto it3 = y.upper_bound(i);
                if(it3 != y.end()) {
                    y.erase(it3);
                }
                it = it2;
            }
        } else if(y.find(i) != y.end()) {
            auto it = y.find(i);
            while(it != y.end()) {
                auto it2 = it++;
                x.erase(it);
                auto it3 = x.upper_bound(i);
                if(it3 != x.end()) {
                    x.erase(it3);
                }
                it = it2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}