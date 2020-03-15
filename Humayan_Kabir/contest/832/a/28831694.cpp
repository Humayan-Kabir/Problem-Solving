#include<bits/stdc++.h>
#define sf1(a) scanf("%d",&a)
using namespace std;
typedef long long int LL;
const int N=123456;
int main()
{
    ios_base::sync_with_stdio(false);
    LL n,k;
    cin>>n>>k;
    LL ans=(n)/k;
    if(ans%2==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    return 0;
}
