#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL ara[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    LL total = 0;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        total += ara[i];
    }
    sort(ara + 1, ara + n + 1);
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int id;
        cin >> id;
        cout << total - ara[n - id + 1] << endl;
    }   
    return 0;
}