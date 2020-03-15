/*input
13
*/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    vector<int> vv;
    int n;
    cin >> n;
    if(n == 2)
    {
        cout <<1<<endl;
        cout <<1 << " "<<1<<endl;
        return 0;
    }
    if(n%2==0)
    {
        int ans = (n/2);
        int mod = 1;
        cout << ans%2<<endl;
        cout << ans;
        for(int i = 1; i<=n; i++)
        {
            if(i%2 == mod) cout <<" "<<i;
            if(i%2==0) mod = !mod; 
        }
        cout << endl;
        return 0;
    }
    if(n%2==1)
    {
        vv.push_back(1);
        vv.push_back(n-1);
        n = n - 3;
        int ans = (n/2);
        cout << ans%2<<endl;
        int now = 2,mod = 1;
        cout << 2 + ans;
        for(int v: vv) cout <<" "<<v;
        for(int i = 1; i<=n; i++)
        {
            if(i%2==mod) cout<<" "<<now;
            if(i%2==0) mod = !mod;
            now++;
        }
        cout << endl;
    }
    return 0;
}
