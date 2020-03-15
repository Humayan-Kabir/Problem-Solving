#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
map< pair<int,int>, int> maping;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        maping.clear();
        maping[{0,0}] = 0;
        int found = 0, res = INT_MAX, l, r, x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == 'L') {
                x--;
            } else if(str[i] == 'R') {
                x++;
            } else if(str[i] == 'U') {
                y++;
            } else {
                y--;
            }
            if(maping.find({x, y}) != maping.end()) {
                int ll = maping[{x, y}] + 1, rr = i + 1;
                if(rr - ll + 1 < res) {
                    res = rr - ll + 1;
                    l = ll; r = rr;
                    found = 1;
                }
            }
            maping[{x, y}] = i + 1;
        }
        if(!found) {
            cout << -1 << endl;
        } else {
            cout << l << " " << r << endl;
        }
    }
    return 0;
}