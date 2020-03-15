#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
using namespace std;
typedef long long int LL;
set<int> st;
int main() { 
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int ans = 0, n;
        st.clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            st.insert(num);
        }
        while(!st.empty()) {
            int it = (*(--st.end()));
            if(it % 2 == 1) {
                st.erase(st.find(it));
                continue;
            }
            ans++;
            st.erase(st.find(it));
            it = it / 2;
            st.insert(it);
        }
        cout << ans << endl;
    }
    return 0;
}