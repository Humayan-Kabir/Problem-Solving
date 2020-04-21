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
int arr[mx], cnt[mx], cnt2[mx];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++) {
            cnt[i] = 0; cnt2[i] = 0;
        }
        int x = 0, y = n, ans = 0;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            arr[i] = num;
            cnt[num]++;
        }
        for(int i = 1; i < n; i++) {
            if(cnt[i] == 2) {
                x = i;
            }
        }
        y = n - x;
        vector<pair<int,int>> vt;
        for(int i = 1; i < n; i++) {
            cnt[arr[i]]--;
            cnt2[arr[i]]++;
            if(i == x || i == y) {
                int flag = 1;
                for(int j = 1; j <= i; j++) {
                    if(cnt2[j] == 1) continue;
                    flag = 0;
                }
                for(int j = 1; j <= n - i; j++) {
                    if(cnt[j] == 1) continue;
                    flag = 0;
                }
                if(flag) {
                    vt.push_back({i, n - i});
                }
            } 
        }
        cout << vt.size() << endl;
        for(auto it : vt) {
            cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}