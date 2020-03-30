/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: Humayan Kabir
 * Time: 2020-03-26 20:39:02
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
map<int,int> maping;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k,low = INT_MAX, high = INT_MIN;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        maping[num]++;
        low = min(low, num); high = max(high, num);
    }
    LL ans = 100000000000000000, precnt = 0, postcnt = 0;
    LL total = 0, leftsum = 0;
    for(auto it : maping) {
        total += 1LL * it.first * it.second;
    }
    for(auto it : maping) {
        if(it.second >= k) {
            ans = 0;
            break;
        }
        LL leftmoves = 0, rightmoves = 0;
        leftmoves = max(0LL,  1LL * (it.first - 1) * precnt - leftsum);
        if(precnt + it.second >= k) {
            ans = min(ans, leftmoves + k - it.second);
        }
        precnt += it.second; leftsum += (1LL * it.first * it.second);
        LL rightcnt = n - precnt, rightsum = total - leftsum;
        rightmoves = max(0LL, rightsum - 1LL * (it.first + 1) * rightcnt);
        if(rightcnt + it.second >= k) {
            ans = min(ans, rightmoves + k - it.second);
        }
        ans = min(ans, leftmoves + rightmoves + k - it.second);
    }
    cout << ans << endl;
    return 0;
}