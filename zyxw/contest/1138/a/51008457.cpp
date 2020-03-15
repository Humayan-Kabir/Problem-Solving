#include <bits/stdc++.h>
#define mx 200007
using namespace std;
int ara[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> vt;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    int cnt = 1;
    for(int i = 2; i <= n; i++) {
        if(ara[i - 1] == ara[i]) cnt++;
        else {
            vt.push_back(cnt);
            cnt = 1;
        }
    }
    vt.push_back(cnt);
    int res = 0;
    for(int i = 1; i < vt.size(); i++) {
        int x = min(vt[i], vt[i - 1]);
        res = max(res, 2 * x);
    }
    cout << res << endl;
    return 0;
}
