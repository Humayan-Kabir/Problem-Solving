#include<bits/stdc++.h>
using namespace std;
const int mx = 22;
typedef long long int LL;
int ara[1<<mx], mainAra[1<<mx], findElement[1 << mx];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int mask;
        cin >> mask;
        mainAra[i] = mask;
        ara[mask] = 1;
        findElement[mask] = mask;
    }
    for(int i = 0; i <= 21; i++) {
        for(int j = 0; j < (1<<mx); j++) {
            if(j & (1 << i)) {
                ara[j] += ara[j ^ (1 << i)];
                if(ara[j ^ (1 << i)] > 0) {
                    findElement[j] = findElement[j ^ (1 << i)];
                }
            }
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        if(ara[((1 << 22) -1 - mainAra[i])] > 0) {
            cout << findElement[((1 << 22) -1 - mainAra[i])] <<" ";
        }
        else {
            cout << -1 <<" ";
        }
        if(i == n) cout << endl;
    }
    return 0;
}
