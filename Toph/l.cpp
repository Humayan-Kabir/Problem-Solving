#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int test = 1; test <= t; test++) {
        int n; cin >> n;
        int flag = 1;
        for(int i = 0; i < 2 * n; i++) {
            int num; cin >> num;
            if ((i & 1) && (num % 2 != 0 || num % 3 != 0)) {
                flag = 0;
            } 
        }
        if (!flag) {
            cout << "Case " << test << ": " << "The number does not meet expectation." << endl;
        } else {
            cout << "Case " << test << ": " << "The number is both square and cube." << endl;
        }
    }
    return 0;
}