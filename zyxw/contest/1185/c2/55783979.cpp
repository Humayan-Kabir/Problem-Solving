#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int ara[mx], cnt[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    for(int i = 1; i <= n; i++) {
        int baki = m - ara[i], total = 1;
        for(int j = 1; j <= 100; j++) {
            if(baki < j) break;
            int possible = baki / j;
            int avail = min(possible, cnt[j]);
            total += avail;
            baki = baki - (avail * j);
        }
        cnt[ara[i]]++;
        cout << i - total << " ";
    }
    cout << endl;
    return 0;
}