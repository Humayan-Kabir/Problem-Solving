#include<bits/stdc++.h>
using namespace std;
#define mx 200007
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int n, x, y;
    cin >> n >> x >> y;
    x++; y++;
    string str;
    cin >> str;
    int leftone = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(str[i] == '1') {
            leftone = i;
            break;
        }
    }
    int ans = 0;
    for(int i = n - x; i < n; i++) {
        if(i == n - x || i == n - y) {
            if(str[i] == '0') {
                ans++;
            }
        }
        else if(str[i] == '1') {
            ans++;
        }
    }
    if(str[n - x] == '0') {
        if(leftone < n - x) {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
