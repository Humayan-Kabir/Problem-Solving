#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int cnt[30];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        cnt[str[0] - 'a']++;
    }
    int ans = 0;
    for(int i = 0; i <= 25; i++) {
        int x = cnt[i] / 2, y = cnt[i] - x;
        ans += (x * (x - 1)) / 2;
        ans += (y * (y - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}
