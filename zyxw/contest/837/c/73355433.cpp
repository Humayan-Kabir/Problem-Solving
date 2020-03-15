/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-03-15 22:53:26
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int check(int x1, int y1, int x2, int y2, int a, int b) {
    int res = x1 * y1 + x2 * y2;
    if((x1 + x2) <= a && max(y1, y2) <= b) return res;
    if((y1 + y2) <= b && max(x1, x2) <= a) return res;
    return 0;
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int,int>> dimentions(n + 1);
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> dimentions[i].first >> dimentions[i].second;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            ans = max(ans, check(dimentions[i].first, dimentions[i].second, dimentions[j].first, dimentions[j].second, a, b));
            ans = max(ans, check(dimentions[i].first, dimentions[i].second, dimentions[j].second, dimentions[j].first, a, b));
            ans = max(ans, check(dimentions[i].second, dimentions[i].first, dimentions[j].first, dimentions[j].second, a, b));
            ans = max(ans, check(dimentions[i].second, dimentions[i].first, dimentions[j].second, dimentions[j].first, a, b));
        }
    }
    cout << ans << endl;
    return 0;
}