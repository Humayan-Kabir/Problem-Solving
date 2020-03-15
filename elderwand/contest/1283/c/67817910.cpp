#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
vector<pair<int,int>> cycleinfo;
int vis[mx], Timer = 0, cycle = 0, last;
stack<int> st;
void dfs(int u) {
    vis[u] = Timer;
    for(int v : graph[u]) {
        if(vis[v] != Timer) {
            dfs(v);
        }
    }
    st.push(u);
}
void dfs2(int u) {
    vis[u] = Timer;
    last = u;
    for(int v : graph[u]) {
        if(vis[v] == Timer) {
            cycle = 1;
        }
        else {
            dfs2(v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if(num == 0) continue;
        graph[i].push_back(num);
    }
    Timer++;
    for(int i = 1; i <= n; i++) {
        if(vis[i] != Timer) {
            dfs(i);
        }
    }
    Timer++;
    while(!st.empty()) {
        int t = st.top();
        st.pop();
        if(vis[t] == Timer) continue;
        cycle = 0;
        int in = t;
        dfs2(t);
        if(cycle == 1) continue;
        cycleinfo.push_back(make_pair(t, last));
    }
    int sz = cycleinfo.size();
    for(int i = 0; i < sz; i++) {
        if(i == sz - 1) {
            graph[cycleinfo[i].second].push_back(cycleinfo[0].first);
        }
        else {
            graph[cycleinfo[i].second].push_back(cycleinfo[i + 1].first);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << graph[i][0] << " ";
    }
    cout << endl;
    return 0;
}