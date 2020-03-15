#include<bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL fibo[mx], vis[200];
char res[mx];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, r, p, s, ans = 0;
        cin >> n >> r >> p >> s;
        string str;
        cin >> str;
        int R = 0, P = 0, S = 0;
        for(int i = 0; i < str.length(); i++) { 
            if(str[i] == 'R') {
                R++;
            }
            if(str[i] == 'P') {
                P++;
            }
            if(str[i] == 'S') {
                S++;
            }  
        }
        ans = min(r, S) + min(p, R) + min(s, P);
        int rr = r, pp = p, ss = s;
        r = min(r, S); p = min(p, R); s = min(s, P);
        rr -= r; pp -= p; ss -= s;
        if(ans >= ((n + 1) / 2)) {
            cout << "YES" << endl;
            vector<char> vt;
            while(rr--) {
                vt.push_back('R');
            }
            while (pp--)
            {
                vt.push_back('P');
            }
            while (ss--)
            {
                vt.push_back('S');
            }
            for(char ch : str) {
                if(ch == 'S') {
                    if(r > 0) {
                        cout << 'R';
                        r--;
                    }
                    else {
                        cout << vt.back();
                        vt.pop_back();
                    }
                }
                if(ch == 'R') {
                    if(p > 0) {
                        cout << 'P';
                        p--;
                    }
                    else {
                        cout << vt.back();
                        vt.pop_back();
                    }

                }
                if(ch == 'P') {
                    if(s > 0) {
                        cout << 'S';
                        s--;
                    }
                    else {
                        cout << vt.back();
                        vt.pop_back();
                    }
                }
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}