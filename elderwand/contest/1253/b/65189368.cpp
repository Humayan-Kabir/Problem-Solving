#include<bits/stdc++.h>
#define mx 300007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
int c[mx], d[mx];
map<int,int> maping;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int flag = 1;
    vector<int> res;
    set<int> st;
    int out = 0;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            if(c[i] < 0) {
                flag = 0;
                break;
            }
            st.insert(c[i]);
        }
        else {
            if(c[i] > 0) {
                if(maping.find(c[i]) == maping.end()) {
                    maping[c[i]] = i;
                }
                else {
                    if(maping[c[i]] > out) {
                        flag = 0;
                    }
                    maping[c[i]] = i;
                }
                if(st.find(c[i]) != st.end()) {
                    flag = 0;
                    break;
                }
                st.insert(c[i]);
            } else {
                if(st.find(c[i] * -1) == st.end()) {
                    flag = 0;
                    break;
                }
                st.erase(st.find(-1 * c[i]));
            }
        }
        if(st.size() == 0) {
            out = i;
            res.push_back(i);
        }
        //cout << flag << " " << i << endl;
    }
    if(flag == 0 || st.size() > 0) cout << -1 << endl;
    else {
        cout << res.size() << endl;
        for(int i = 0; i < res.size(); i++) {
            if(i == 0) cout << res[i];
            else cout << " " << res[i] - res[i - 1];
        }
        cout << endl;
    }
        
    return 0;
}
