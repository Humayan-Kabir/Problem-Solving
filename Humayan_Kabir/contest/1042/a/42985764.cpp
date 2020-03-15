#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int LL;
int main()
{
    ios_base::sync_with_stdio(false);
    LL n, m;
    cin >> n >> m;
    LL total = 0, mx = 0;
    for(int i = 1; i<=n; i++)
    {
        LL num;
        cin >> num;
        total += num;
        mx = max(mx, num);
    }
    total += m;
    LL kk = ((total + n - 1) / n);
    if(kk <= mx)
    {
        cout << mx <<" " << mx + m << endl;
    }
    else
    cout << kk << " " << mx + m << endl;
    return 0;
}
