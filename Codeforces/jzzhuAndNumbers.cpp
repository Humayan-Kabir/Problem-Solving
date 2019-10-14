#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int counter[1 << 20], pw[1 << 20];
void init() {
    pw[0] = 1;
    for(int i = 1; i < (1 << 20); i++) {
        pw[i] = (pw[i - 1] * 2) % mod;
    }
}
int main() {
    init();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        counter[num]++;
    }
    for(int j = 19; j >= 0; j--) {
        for(int i = (1 << 20) - 1; i >= 0; i--) {
            if(i & (1 << j)) continue;
            counter[i] += counter[i | (1 << j)];
        }
    }
    long long int ans = 0;
    for(int i = 0; i < (1 << 20); i++) {
        int bit = __builtin_popcount(i);
        if(bit & 1) ans -= pw[counter[i]];
        else ans += pw[counter[i]];
        ans = (ans + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}