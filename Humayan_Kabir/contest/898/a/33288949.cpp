/*input
9
*/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int mod = n % 10;
    int ans = n;
    if(mod<=5) ans = n - mod;
    else ans = n - mod + 10;
    cout << ans <<endl;
    return 0;
}
