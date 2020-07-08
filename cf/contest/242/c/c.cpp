/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-10 03:58:16
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
map<pii, bool> isExist;
map<pii, int> dist;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    isExist[{x1, y1}] = 1; isExist[{x2, y2}] = 1; 
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for(int j = a; j <= b; j++) {
            isExist[{r, j}] = 1;
        }
    }
    dist[{x1, y1}] = 0;
    queue<pii> q; 
    q.push({x1, y1});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int d = dist[{x, y}]; 
        q.pop();
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(dist.count({x + i, y + j}) || !isExist.count({x + i, y + j})) continue;
                dist[{x + i, y + j}] = d + 1;
                q.push({x + i, y + j});
            }
        }
    }
    if(dist.count({x2, y2})) {
        cout << dist[{x2, y2}] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}