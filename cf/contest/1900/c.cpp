#include<bits/stdc++.h>
using namespace std;
const int N = 300007;
char s[N];
int L[N], R[N];
int ans;
void dfs(int p, int cost) {
    int l = L[p];
    int r = R[p];
    if (l == 0 && r == 0) {
        ans = min(ans, cost);
        return;
    } 
    if (l != 0) {
        dfs(l, cost + (s[p] != 'L'));
    }
    if (r != 0) {
        dfs(r, cost + (s[p] != 'R'));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        for(int i = 0; i < n; i++) {
            s[i + 1] = str[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> L[i] >> R[i];
        }
        ans = N;
        dfs(1, 0);
        cout << ans << endl;
    }   
    return 0;
}