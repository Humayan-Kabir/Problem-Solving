#include<bits/stdc++.h>
#define mx 300007
#define up 1000000000
using namespace std;
typedef long long int LL;
int ara[mx], n, k;
int checkinter(int x1, int y1, int x2, int y2) {
    if(y1 < x2 || x1 > y2) return 0;
    return 1;
}
int check(int mid) {
    int left = 0, right = 1e9;
    for(int i = 1; i <= n; i++) {
        if(ara[i] == -1) {
            if(ara[i - 1] != -1) {
                int l = max(0, ara[i - 1] - mid), r = min(ara[i - 1] + mid, up);
                if(!checkinter(left, right, l, r)) return 0;
                left = max(left, l); right = min(right, r);
            }
            if(ara[i + 1] != -1) {
                int l = max(0, ara[i + 1] - mid), r = min(ara[i + 1] + mid, up);  
                if(!checkinter(left, right, l, r)) return 0;
                left = max(left, l); right = min(right, r);
            }
        }
    }
    if(left > right) return 0;
    k = (left + right) / 2;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        int curans = 0;
        for(int i = 1; i < n; i++) {
            if(ara[i] >= 0 && ara[i + 1] >= 0) {
                curans = max(curans, abs(ara[i] - ara[i + 1]));
            }
        }
        ara[n + 1] = -1;
        ara[0] = -1;
        int low = curans, high = 1e9, res = 1e9 + 1, num;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(mid)) {
                res = mid;
                num = k;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << res << " " << num << endl;
    }
    return 0;
}