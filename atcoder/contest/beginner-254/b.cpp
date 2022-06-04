#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> previous, current; 
    while(n--) {
        for(int i = 0; i < previous.size(); i++) {
            int element = previous[i] + (i - 1 >= 0 ? previous[i - 1] : 0);
            current.push_back(element);
        }
        current.push_back(1);
        for(int i = 0; i < current.size(); i++) {
            if(i > 0) cout << " ";
            cout << current[i];
        }
        cout << endl;
        previous = current;
        current.clear();
    }
    return 0;
}