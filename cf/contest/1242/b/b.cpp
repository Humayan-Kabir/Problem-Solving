/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-24 03:19:42
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    set<pair<int,int>> myset;
    map<int,int> maping;
    for(int v : graph[1]) {
        myset.insert({1, v});
        maping[v] = 1;
    }
    for(int i = 2; i <= n; i++) {
        if(maping.find(i) == maping.end()) {
            myset.insert({0, i});
            maping[i] = 0;
        }
    }
    int ans = 0, counter = 1;
    while(counter < n) {
        int u = myset.begin()->second, connected = myset.begin()->first;
        if(connected == counter) {
            ans++;
        }
        myset.erase(myset.begin());
        maping.erase(u);
        for(int v : graph[u]) {
            if(maping.find(v) != maping.end()) {
                myset.erase({maping[v], v});
                maping[v]++;
                myset.insert({maping[v], v});
            }
        }
        counter++;
    }
    cout << ans << endl;
    return 0;
}