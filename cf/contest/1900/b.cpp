#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N][N][N];
int A = 1, B = 2, C = 4;
int init(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0 || a > 102 || b > 102 || c > 102) return 0;
    int &ret = dp[a][b][c];
    if (ret != -1) {
        return ret;
    }
    else if (a == 1 && b == 1 && c == 1) {
        return ret = A + B + C;
    } else if (a == 0 && b == 1 && c == 1) {
        return ret = A;
    } 
    else if (a == 1 && b == 1 && c == 0) {
        return ret = C;
    } 
    else if (a == 1 && b == 0 && c == 1) {
        return ret = B;
    } 
    int result = 0;
    if (a > 0 && b > 0) {
        result |= init(a - 1, b - 1, c + 1);
    }
    if (a > 0 && c > 0) {
        result |= init(a - 1, b + 1, c - 1);
    }
    if (b > 0 && c > 0) {
        result |= init(a + 1, b - 1, c - 1);
    }
    return ret = result;
}
int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    while(n--) {
        int a, b, c; cin >> a >> b >> c;
        init(a, b, c);
        int result = init(a, b, c);
        for(int i = 0; i < 3; i++) {
            if (i > 0) cout << " ";
            bool checked = result & (1 << i);
            cout << checked;
        }
        cout << endl;
    }
}