/*input
7
1 1 2 3 1 4
3 3 1 1 1 2 3
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
int ans = 1;
int color[mx];
void dfs(int u,int par,int col)
{
    if(color[u] != col) {
        ans++;
        col = color[u];
    }
    for(int v : graph[u])
    {
        if(v == par) continue;
        dfs(v,u,col);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 2; i<=n; i++)
    {
        int x;
        cin >> x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    for(int i = 1; i<=n; i++) cin >> color[i];
    dfs(1,1,color[1]);
    cout << ans << endl;
    return 0;
}