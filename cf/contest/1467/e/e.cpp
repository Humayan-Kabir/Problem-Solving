/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-08 22:06:07
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 200007

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int cnt[N], sz[N], st[N], ft[N], ver[N], col[N], counter[N], d[N], x[N], Timer = 0;
vector<int> g[N];
void rec(int v, int p){
    sz[v] = 1;  // every vertex has itself in its subtree
    st[v] = ++Timer;
    ver[st[v]] = v;
    for(auto u : g[v])
        if(u != p){
            rec(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
    ft[v] = Timer;
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    int flag = 1;
    for(auto u : g[v])
        if(u != p && u != bigChild) {
            dfs(u, v, 0);
            flag = flag & d[u];  
        }
    if(bigChild != -1) {
        dfs(bigChild, v, 1);
        flag = flag & d[bigChild];  
    }  // bigChild marked as big and not cleared from cnt
    for(auto u : g[v])
	if(u != p && u != bigChild)
	    for(int p = st[u]; p <= ft[u]; p++)
		cnt[ col[ ver[p] ] ]++;


    cnt[ col[v] ]++;
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.


    if(flag) {
        if(cnt[col[v]] == 1) {
            d[v] = 1;
        } else {
            d[v] = 0;
        }   
    } else {
        d[v] = 0;
    }

    if(cnt[col[v]] == counter[col[v]]) {
        x[v] = 1;
    }
    // debug("dfs",v, flag, d[v], x[v]);

    if(keep == 0)
        for(int p = st[v]; p <= ft[v]; p++)
	    cnt[ col[ ver[p] ] ]--;
}
map<int,int> maping;
int hh = 0, ans = 0;
int genjam[N];
void hudai(int u, int p) {
    for(int v : g[u]) {
        if(v != p) {
            if(d[v] == 0) genjam[u]++;
            hudai(v, u);
        }
    }

}
void fun(int u, int p, int total) {
    for(int v : g[u]) {
        if(v != p) {
            int xx = genjam[u] - (d[v] == 0);
            fun(v, u, (xx > 0) | total);
        }
    }
    if(total == 0 && d[u] && x[u] == 1) {
        ans++;
        debug("res", u);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if(maping.find(num) == maping.end()) {
            hh++;
            maping[num] = hh;
        }
        col[i] = maping[num];
        counter[col[i]]++;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    rec(1, -1);
    dfs(1, -1, 1);
    hudai(1, -1);
    fun(1, -1, 0);
    cout << ans << endl;
    return 0;
}
