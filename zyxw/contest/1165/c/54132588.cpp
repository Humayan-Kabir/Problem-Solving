#include<bits/stdc++.h>
using namespace std;
#define mx 200007
typedef long long int LL;
string str;
int n;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    queue<char> Q;
    string ans = "";
    Q.push(str[0]);
    for(int i = 1; i < n; i++) {
        if(Q.empty()) {
            Q.push(str[i]);
            continue;
        }
        if(Q.front() != str[i]) {
            ans += Q.front();
            ans += str[i];
            Q.pop();
        }
    }
    int len = ans.length();
    cout << n - len << endl;
    cout << ans << endl;
    return 0;
}
