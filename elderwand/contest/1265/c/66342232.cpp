#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define mx 400007
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
int arr[mx], vt[mx];
int main() {
    ios_base::sync_with_stdio(false); 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cnt = 0, pre = 0, pos = 0;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            if(i == 1) {
                pre = num;
                cnt = 1;
                continue;
            }
            if(pre == num) {
                cnt++;
                continue;
            } 
            if(pre != num) {
                vt[++pos] = cnt;
                pre = num; cnt = 1;
            }
        }
        vt[++pos] = cnt;
        int sum = 0, g = 0, s = 0, b = 0;
        for(int i = 1; i <= pos; i++) {
            sum += vt[i];
            if(sum > (n/2)) break;
            if(g == 0) {
                g += vt[i];
                continue;
            }
            if(s <= g) {
                s += vt[i];
                continue;
            }
            b += vt[i];
        }
        // cout << g << " " << s << " " << b << endl;
        if(g >= 1 && s >= 1 && b >= 1 && g < s && g < b) {
            cout << g << " " << s << " " << b << endl;
        } else {
            cout << 0 << " " << 0 << " " << 0 << endl;
        }
    }
    return 0;
}
