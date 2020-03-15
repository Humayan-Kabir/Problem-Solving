#include<bits/stdc++.h>
#define mx 100007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL base[mx], Hash[mx], ans[mx], b = 256;
vector<int> edge[mx];
map<LL,int> maping;
int vis[mx], unq = 0;
void dfs(int u) {
    if(vis[u] == 0) unq++;
    vis[u] = 1;
    for(int v : edge[u]) {
        if(vis[v] == 0) {
            dfs(v);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        int n, sum = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int num;
            cin>>num;
            sum += num;
        }
        cout << (sum + n - 1) / n << endl;
    }
    return 0;
}
