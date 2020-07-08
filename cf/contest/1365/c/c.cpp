/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-07-08 12:24:05
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int n, a[mx], b[mx], pos[mx];
int calculate(int arr[], int brr[]) {  
    map<int,int> maping;
    map<int,int> counter;
    for(int i = 1; i <= n; i++) pos[arr[i]] = i;
    for(int i = 1; i <= n; i++)  maping[pos[brr[i]] - i]++;
    int ans = maping[0];
    for(int i = 1; i <= n; i++) {
        int rm = pos[brr[i]] - i;
        counter[rm]++;
        maping[rm]--;
        int curans = maping[-i] + counter[n - i];
        ans = max(ans, curans);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    cout << max(calculate(a, b), calculate(a, b)) << endl;
    return 0;
}