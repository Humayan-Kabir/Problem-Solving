#include<bits/stdc++.h>
#define mod 1000000007
#define mx 3000007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
LL ara[50];
int main() {
    ios_base::sync_with_stdio(false);
    LL n, p;
    cin >> n >> p;
    int ans = -1;
    for(int i = 1; i < 50; i++) {
        LL num = n - (i * p);
        if(num <= 0) {
            continue;
        }
        LL now = 0;
        for(int i = 0; i < 50; i++) {
            if(num & (1LL << i)) now++;
        }
        if(now > i) continue;
        if(i <= num) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}