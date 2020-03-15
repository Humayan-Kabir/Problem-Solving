#include <bits/stdc++.h>
#define mod 1000000007
#define mx 100007
using namespace std;
typedef long long int LL;
int n, root, ara[mx];
vector <int> vt;
vector <int> graph[mx];
void dfs(int u, int p) {
    int color = ara[u], cnt = 0;
    for(int v : graph[u]) {
        if(v != p) {
            color = color & ara[v];
            dfs(v, u);
            cnt = 1;
        }
    }
    if(color) {
        vt.push_back(u);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        ara[i] = y;
        if(x == -1) {
            root = i;
            continue;
        }
        graph[x].push_back(i);
    }
    dfs(root, -1);
    if(vt.size() == 0) {
        cout << -1 << endl;
    }
    else {
        sort(vt.begin(), vt.end());
        for(int v : vt) {
            cout << v <<" ";
        }
        cout << endl;
    }
    return 0;
}
