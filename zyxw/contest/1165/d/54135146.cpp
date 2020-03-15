#include<bits/stdc++.h>
using namespace std;
#define mx 200007
typedef long long int LL;
LL ara[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> maping;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            maping[ara[i]] = 1;
        }
        maping[1] = 1;
        sort(ara + 1, ara + n + 1);
        int flag = 0;
        LL ans = ara[1] * ara[n];
        for(int i = 1; i <= n; i++) {
            if(ara[i] * ara[n - i + 1] != ans) {
                flag = 1;
            }
        }
        if(flag) {
            cout << -1 << endl;
        }   
        else {
            int now = 0;
            LL root = sqrt(ans);
            maping[ans] = 1;
            for(LL i = 1; i <= root; i++) {
                if(ans % i == 0) {
                    if(maping.find(i) == maping.end()) {
                        now = 1;
                    }
                    LL y = ans / i;
                    if(maping.find(y) == maping.end()) {
                        now = 1;
                    }
                }
                if(now == 1) break;
            }
            if(now) cout << -1 << endl;
            else 
            cout << ans << endl;
        }

    }
    return 0;
}