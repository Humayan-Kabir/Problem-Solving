/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-11 10:10:00
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int arr[1024], counter1[1024], counter2[1024];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(counter1, 0, sizeof counter1);
        memset(counter2, 0, sizeof counter2);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            counter1[arr[i]] = 1;
        }
        int ans = -1;
        for(int i = 1; i < 1024; i++) {
            memset(counter2, 0, sizeof counter2);
            int flag = 1;
            for(int j = 1; j <= n; j++) {
                int num = arr[j] ^ i;
                counter2[num]++;
                if(counter1[num] == 0 || counter2[num] > 1) {
                    flag = 0;
                }
            }
            if(flag) {
                ans = i; break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}