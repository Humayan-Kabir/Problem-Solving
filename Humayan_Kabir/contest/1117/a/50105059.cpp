#include <bits/stdc++.h>
#define mx 100007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int n, MAX = 0;
    cin >> n;
    vector <int> vt;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        vt.push_back(num);
        MAX = max(MAX, num);
    }
    int cnt = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(vt[i]==MAX) cnt++;
        ans = max(ans, cnt);
        if(vt[i] != MAX) cnt = 0;
    }
    cout << ans << endl;
    return 0;
}
