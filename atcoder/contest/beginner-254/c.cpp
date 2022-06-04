#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    deque<int> q[k];
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        q[i % k].push_back(num);
    }
    for(int i = 0; i < k; i++) {
        sort(q[i].begin(), q[i].end());
    }
    vector<int> temp(n);
    for(int i = 0; i < n; i++) {
        temp[i] = q[i % k].front();
        q[i % k].pop_front();
        if (i > 0 && temp[i - 1] > temp[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}