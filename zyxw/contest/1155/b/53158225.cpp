#include<bits/stdc++.h>
using namespace std;
#define mx 300007
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int move = (n - 11) / 2;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(n - i == 10) break;
        if(str[i] == '8') cnt++;
    }
    if(cnt > move) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
