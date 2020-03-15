#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
vector<int> divisors[20007];
void fun() {
    for(int i = 1; i <= 20000; i++) {
        for(int j = i; j <= 20000; j += i) {
            divisors[j].push_back(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    fun();
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        LL ans = INT_MAX, x, y, z;
        for(int i = 1; i <= 20000; i++) {
            LL res = abs(i - b), pre = INT_MAX, pos = INT_MAX;
            int uu, vv;
            for(int v : divisors[i]) {
                if(abs(a - v) < pre) {
                    pre = abs(a - v);
                    uu = v;
                } 
            }
            for(int j = i; j <= 20000; j+=i) {
                if(abs(j - c) < pos) {
                    pos = abs(j - c);
                    vv = j;
                }
            }
            res = res + pre + pos;
            if(res < ans) {
                ans = res;
                x = uu; y = i; z = vv;
            }
        }
        cout << ans << endl;
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}