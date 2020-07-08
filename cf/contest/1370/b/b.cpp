/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-06-20 20:47:44
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
        int n;
        cin >> n;
        vector<int> even, odd;
        for(int i = 1; i <= 2 * n; i++) {
            int x;
            cin >> x;
            if(x & 1) {
                odd.push_back(i);
            } else {
                even.push_back(i);
            }
        }
        int counter = 0;
        for(int i = 0; (i + 1) < even.size(); i+=2) {
            if(counter == n - 1) break;
            cout << even[i] << " " << even[i + 1] << endl;
            counter++;
        }
        for(int i = 0; (i + 1) < odd.size(); i+=2) {
            if(counter == n - 1) break;
            cout << odd[i] << " " << odd[i + 1] << endl;
            counter++;
        }
    }
    return 0;
}