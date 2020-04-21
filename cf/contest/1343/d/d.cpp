/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-04-21 20:35:01
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200107
using namespace std;
typedef long long int LL;
int cnt[2 * mx], counter[2 * mx], arr[mx];
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
             cin >> arr[i]; 
        }
        for(int i = 0; i <= 2 * k + 10; i++) {
            cnt[i] = 0; counter[i] = 0;
        }
        int paircnt = (n / 2), ans = 0;
        for(int i = 1, j = n; i <= j; i++, j--) {
            if(arr[i] > k && arr[j] > k) {
                ans += 2;
                paircnt--;
                continue;
            }
            int l, r;
            if(arr[i] <= k && arr[j] <= k) {
                counter[arr[i] + arr[j]]++;
                l = min(arr[i], arr[j]) + 1; r = min(2 * k + 7, max(arr[i], arr[j]) + k);
            } else {
                l = min(arr[i], arr[j]) + 1; r = min(2 * k + 7, min(arr[i], arr[j]) + k);
            }

            cnt[l] += 1; cnt[r + 1] -= 1;
        }
        int now = paircnt * 2;
        for(int i = 1; i <= 2 * k; i++) {
            cnt[i] = cnt[i - 1] + cnt[i];
            int rem = (paircnt - cnt[i]) * 2 + cnt[i] - counter[i];
            now = min(now, rem);
        }
        cout << ans + now << endl;
    }
    return 0;
}