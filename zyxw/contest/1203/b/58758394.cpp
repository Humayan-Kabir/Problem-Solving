#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int dp[mx], cnt[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        vector<int> vt;
        for(int i = 1; i <= 4 * n; i++) {
            int num;
            cin >> num;
            vt.push_back(num);
        }
        sort(vt.begin(), vt.end());
        int area = vt[0] * vt[(4 * n) - 1], l = 4 * n, flag = 0;
        for(int i = 0; i < n; i++) {
            int a = i * 2, b = a + 1, d = l - a - 1, c = l - b - 1;
            if(vt[a] != vt[b]) flag = 1;
            if(vt[c] != vt[d]) flag = 1;
            if(vt[a] * vt[c] != area) flag = 1;
            if(flag) break; 
        }
        if(flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
