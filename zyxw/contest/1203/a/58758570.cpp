#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            ara[n + i] = ara[i];
        }
        int res = 0, counter = 0;
        for(int i = 1; i <= 2 * n; i++) {
            if(i == 1) {
                counter = 1;
                continue;
            }
            if(ara[i] > ara[i - 1]) {
                counter++;
            }
            else {
                counter = 1;
            }
            res = max(res, counter);
        }
        counter = 0;
        for(int i = 1; i <= 2 * n; i++) {
            if(i == 1) {
                counter = 1;
                continue;
            }
            if(ara[i] < ara[i - 1]) {
                counter++;
            }
            else {
                counter = 1;
            }
            res = max(res, counter);
        }
        if(res >= n) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
