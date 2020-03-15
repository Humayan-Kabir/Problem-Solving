#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int dp1[mx], dp2[mx];
inline int check(int mid, int len1, int len2) {
    for(int i = 1; i <= len1; i++) {
        int r = i + mid;
        if(i + mid -1 > len1) break;
        if(dp1[i - 1] + dp2[r] >= len2) {
            return 1;
        } 
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int len1 = s.length(), len2 = t.length();
    if(len1 == len2) {
        cout << 0 << endl;
        return 0;
    }
    int pos2 = 0, counter = 0;
    for(int i = 1; i <= len1; i++) {
       if(pos2 < len2) {
           if(s[i - 1] == t[pos2]) {
               pos2++;
               counter++;
           }
       }
       dp1[i] = counter;
    }
    pos2 = len2 - 1; counter = 0;
    for(int i = len1; i >= 1; i--) {
        if(pos2 >= 0) {
            if(s[i - 1] == t[pos2]) {
                counter++;
                pos2--;
            }
        }
        dp2[i] = counter;
    }
    int ans = 0, low = 0, high = len1 - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(mid, len1, len2)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
