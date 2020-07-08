/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-31 21:11:10
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int counter = 0;
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            if(u == x || v == x) {
                counter++;
            }
        }
        if(counter == 1 || n == 1) {
            cout << "Ayush" << endl;
            continue;
        }
        if((n - 2) % 2 == 0) {
            cout << "Ayush" << endl;
        } else {
            cout << "Ashish" << endl;
        }
    }
    return 0;
}