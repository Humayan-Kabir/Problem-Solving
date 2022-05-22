#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int test = 1; test <= t; test++) {
        int n; cin >> n;
        string str; cin >> str;
        bool uppercase = 0, lowercase = 0, digit = 0, special = 0;
        for(int i = 0; i < n; i++) {
            if (isalpha(str[i])) {
                if (isupper(str[i])) uppercase = true;
                else lowercase = true;
            }
            if (isdigit(str[i])) digit = true;
            if (str[i] == '#' || str[i] == '&' || str[i] == '*' || str[i] == '@') special = true;
        }
        if (!uppercase) str.push_back('A');
        if (!lowercase) str.push_back('a');
        if (!digit) str.push_back('1');
        if (!special) str.push_back('#');
        while(str.length() < 7) str.push_back('a');
        cout <<"Case #" << test<< ": "<< str << endl;
    }
    return 0;
}