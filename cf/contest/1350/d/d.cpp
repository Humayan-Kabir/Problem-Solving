/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-15 00:44:58
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        int lessEq = 0, greaterEq = 0, flag = 0, valid = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] <= k) lessEq++;
            if(arr[i] >= k) greaterEq++;
            if(arr[i] == k) valid = 1;
            arr[i] = (arr[i] >= k ? 1: 0);
            int counter = 0;
            for(int j = i; j >= i - 3 + 1 && j >= 0; j--) {
                counter += arr[j];
            }
            if(counter >= 2) flag  = 1;
        }
        if(valid && (lessEq <= ((n + 1) / 2) || flag)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}