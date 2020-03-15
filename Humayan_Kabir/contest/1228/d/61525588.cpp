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
    base[0] = 1;
    for(int i = 1; i < mx; i++) {
        base[i] = (base[i - 1] * b) % mod;
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        Hash[u] = (Hash[u] + (v * base[v]) % mod) % mod;
        Hash[v] = (Hash[v] + (u * base[u]) % mod) % mod;
    }
    int counter = 0;
    for(int i = 1; i <= n; i++) {
        if(maping.find(Hash[i]) == maping.end()) {
            maping[Hash[i]] = ++counter; 
        }
    }
    if(counter != 3) {
        cout << -1 << endl;
    }
    else {
        vector<int> group[4];
        for(int i = 1; i <= n; i++) {
            group[maping[Hash[i]]].push_back(i);
        }
        for(int i = 1; i <= 3; i++) {
            memset(vis, 0, sizeof vis);
            unq = 0;
            for(int v : group[i]) {
                dfs(v);
            }
            if(unq < n) {
                cout << -1 << endl;
                return 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            cout << maping[Hash[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}
