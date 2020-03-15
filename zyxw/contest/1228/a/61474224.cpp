#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int check(int num) {
    vector<int> vt;
    set<int> st;
    while(num > 0) {
        vt.push_back(num % 10);
        st.insert(num % 10);
        num = num / 10;
    }
    if(vt.size() == st.size()) return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int l, r, flag = 0;
    cin >> l >> r;
    for(int i = l; i <= r; i++) {
        if(check(i)) {
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        cout << -1 << endl;
    }
    return 0;
}
