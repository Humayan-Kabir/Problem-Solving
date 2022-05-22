#include<bits/stdc++.h>
using namespace std;
inline bool isPallindrome(string str, int len) {
    string temp = str;
    reverse(temp.begin(), temp.end());
    // cout << temp <<  " :: " << str << endl;
    return str == temp;
}
int check(string str) {
    int counter = 0;
    queue<string> q;
    q.push(str);
    while(!q.empty()) {
        string t = q.front();
        q.pop();
        int len = t.length();
        if (len == 0) {
            continue;
        }
        for(int i = 0; i < len; i++) {
            string temp = t;
            temp.erase(temp.begin() + i);
            cout << "temp : " << temp << endl;
            if (isPallindrome(temp, len - 1)) {
                counter++;
            }
            cout << "counter: " << counter << endl;
            q.push(temp);   
        }
    }
    return counter;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        int cnt = check(str);
        cout << cnt << endl;
    }
    return 0;
}