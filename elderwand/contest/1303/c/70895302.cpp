#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int vis[30], vis2[30], Timer = 0, cycle, last;
string ans;
set<int> graph[30];
void dfs1(int u, int par) {
    vis[u] = Timer;
    last = u;
    for(auto v : graph[u]) {
        if(v == par) continue;
        if(vis[v] == Timer) {
            cycle = 1;
            break;
        } else {
            dfs1(v, u);
        }
    }
}
void dfs2(int u, int par) {
    char ch = 'a' + u;
    ans += ch;
    vis2[u] = Timer;
    for(auto v : graph[u]) {
        if(v == par) continue;
        if(vis2[v] == Timer) {
            cycle = 1;
            break;
        } else {
            dfs2(v, u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        ++Timer; cycle = 0;
        string str;
        cin >> str;
        int len = str.length();
        for(int i = 1; i < len; i++) {
            graph[str[i - 1] - 'a'].insert(str[i] - 'a');
            graph[str[i] - 'a'].insert(str[i - 1] - 'a');
        }
        int flag = 0; ans = "";
        for(int i = 0; i < 26; i++) {
            if(graph[i].size() > 2) flag = 1;
            if(vis[i] != Timer) {
                dfs1(i, -1);
                dfs2(last, -1);
            }
        }
        
        flag |= cycle;
        if(flag) {
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
            cout << ans << endl;
        }
        for(int i = 0; i < 27; i++) graph[i].clear();
    }
    return 0;
}