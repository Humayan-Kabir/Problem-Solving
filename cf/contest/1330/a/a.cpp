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
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int arr[201];
        memset(arr, 0, sizeof arr);
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            arr[num] = 1;
        }
        int ans = 0, sum = 0;
        for(int i = 1; i <= 200; i++) {
            if(arr[i] == 0) {
                sum++;
            }
            if(sum <= k) {
                ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}