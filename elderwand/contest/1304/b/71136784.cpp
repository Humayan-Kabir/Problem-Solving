#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
multiset<string> st;
multiset<string> another;
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
       string str;
       cin >> str;
       st.insert(str);
    }
    int ans = 0, cnt = 0;
    string res1 = "",res2 = "", extra = "";
    while(!st.empty()) {
       string cur = *st.begin();
       string rev = cur;
       reverse(rev.begin(), rev.end());
       st.erase(st.find(cur));
       int flag = 0;
       if(!st.empty()) {
          if(st.find(rev) != st.end()) {
             flag = 1;
             res1 += cur;
             res2 = rev + res2;
             st.erase(st.find(rev));
          }
       }
       if(flag == 0 && cnt == 0) {
          if(cur == rev) {
             cnt = 1;
             extra = cur;
          }
       }
    }
    res1 = res1 + extra + res2;
    cout << res1.size() << endl;
    cout << res1 << endl;
    return 0;
}