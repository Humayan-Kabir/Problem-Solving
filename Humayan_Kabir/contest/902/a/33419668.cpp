/*input
3 7
0 4
2 5
6 7
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int n,m;
int ara[110];
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    vector< pair<int,int> > vv;
    for(int i = 1; i<=n; i++)
    {
        int x,y;
        cin >> x >> y;
        vv.push_back(make_pair(x,-y));
    }
    sort(vv.begin(), vv.end());
    ara[vv[0].first] = 1;
    for(int i = 0; i<vv.size(); i++)
    {
        int y = vv[i].first;
        if(ara[y])
        {
            for(int j = y; j<=(-1 *vv[i].second); j++)
            {
                ara[j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i<=m; i++) cnt+=ara[i];
    if(cnt == m+1) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return 0;
}