#include <bits/stdc++.h>
using namespace std;
int cnt[101];
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        cnt[num % k]++;
    }
    int ans = cnt[0] / 2;
    for(int i = 1; i <= k; i++) {
        int y = k - i;
        if(y < i) break;
        if(y == i) {
            ans += (cnt[y] / 2);
        }
        else {
            ans += min(cnt[i], cnt[y]);
        }
    }
    cout << ans * 2 << endl;
    return 0;
}
