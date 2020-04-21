/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-04-03 20:35:51
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int arr[mx], ans[mx], res[mx];
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    LL sum = 0;
    for(int i = 1; i <= m; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum < n) {
        cout << -1 << endl;
        return 0;
    }
    int covered = 0, flag = 1;
    for(int i = m; i >= 1; i--) {
       int need = max(0, arr[i] - covered);
       int was = n - covered - i + 1;
       int give = max(need, min(arr[i], was));
       if(give == 0) flag = 0;
       covered += give;
       res[i] = n - covered + 1;
    }
    if(!flag) cout << -1 << endl;
    else {
        for(int i = 1; i <= m; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}