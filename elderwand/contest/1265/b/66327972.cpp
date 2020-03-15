#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define mx 300007
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
int arr[mx], pos[mx];
int main() {
    ios_base::sync_with_stdio(false); 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            pos[arr[i]] = i;
        }
        int low = 1e9, high = -1e9;
        for(int i = 1; i <= n; i++) {
            low = min(low, pos[i]);
            high = max(high, pos[i]);
            if(high - low + 1 == i) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    return 0;
}
