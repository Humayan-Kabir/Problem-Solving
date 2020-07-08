/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-11 11:15:22
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 500007
using namespace std;
typedef long long int LL;
set<int> graph[mx];
set<int> SZ[mx];
vector<int> color[mx];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        color[num].push_back(i);
    }
    int flag = 1;
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        sort(color[i].begin(), color[i].end(), [=](int i, int j) {
            return SZ[i].size() < SZ[j].size();
        });
        for(int v : color[i]) {
            if(SZ[v].size() == i - 1) {
                res.push_back(v);
            } else {
                flag = 0; break;
            }
            for(int to : graph[v]) {
                graph[to].erase(v);
                SZ[to].insert(i);
            }
        }
    }
    if(!flag) cout << -1 << endl;
    else {
        for(int v : res) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;  
}