#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
string fun(string str) {
    int len = str.length();
    if(len == 1) return str;
    vector<int> position;
    int mark = -1, val = INT_MIN;
    for(int i = 0; i < len; i++) {
        char ch = str[i] - 1;
        if(i == 0) {
            if(str[i + 1] == ch) {
                position.push_back(i);
            }
        } 
        else if(i == len - 1) {
            if(str[i - 1] == ch) {
                position.push_back(i);
            }
        } else {
            if(str[i - 1] == ch || str[i + 1] == ch) {
                position.push_back(i);
            }
        }
    }
    for(int v : position) {
        int id = str[v];
        if(id > val) {
            val = id;
            mark = v;
        }
    }
    string ans = "";
    if(mark == -1) return str;
    for(int i = 0; i < len; i++) {
        if(i == mark) {
            continue;
        }
        ans += str[i];
    }
    // cout << mark << endl;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    string str;
    int len;
    cin >> len;
    cin >> str;
    while(str != fun(str)) {
        str = fun(str);
        // cout << str << endl;
    }
    cout << len - str.length() << endl;
    return 0;

}