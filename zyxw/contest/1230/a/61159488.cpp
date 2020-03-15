    #include <bits/stdc++.h>
    #define mx 200007
    using namespace std;
    typedef long long int LL;
    int dp[mx], cnt[mx];
    int main(int argc, char const *argv[])
    {
        ios_base::sync_with_stdio(false);
        int a[5], total = 0;
        for(int i = 0; i < 4; i++) {
            cin >> a[i];
            total += a[i];
        }
        if(total % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
        for(int i = 0; i < (1 << 4); i++) {
            int t = 0;
            for(int j = 0; j < 4; j++) {
                if(i & (1 << j)) {
                    t += a[j];
                }
            }
            if(t == (total / 2)) {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
        return 0;
    }