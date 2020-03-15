#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        vector<int> vt[1001];
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            vt[x].push_back(y);
        }
        int flag = 1, pre = 0; string str = "";
        for(int i = 0; i <= 1000 && n > 0; i++) {
            sort(vt[i].begin(), vt[i].end());
            for(int v : vt[i]) {
                if(v < pre) flag = 0;
                for(int j = pre; j < v; j++) str += 'U';
                pre = max(v, pre); n--;
            }
            if(n > 0) str += 'R';
        }
        if(!flag) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << str << endl;
        }
    }
    return 0;
}