#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("second_friend_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        int r, c; cin >> r >> c;
        bool flag = false;
        for(int i = 0; i < r; i++) {
            string str; 
            cin >> str;
            for(char ch : str) {
                flag |= (ch == '^');
            }
        }
        if (flag && (r == 1 || c == 1)) {
            cout << "Case #" << i << ": Impossible" << endl;
        } else {
            cout << "Case #" << i << ": Possible" << endl;
            char ch = (flag ? '^' : '.');
            string res(c, ch);
            for(int i = 0; i < r; i++) {
                cout << res << endl;
            }
        }
    }
    return 0;
}