#include <bits/stdc++.h>
#define mx 5007
using namespace std;
int cnt[5][5];
void fun(string stA, string stB, int n, int a, int b, int c, int d) {
    for (int i = 0; i < n; i++)
    {
        int x = stA[i] - '0';
        int y = stB[i] - '0';
        if (x == 1 && y == 1 && a > 0)
        {
            cout << i + 1 << " ";
            a--;
        }
        if (x == 1 && y == 0 && b > 0)
        {
            cout << i + 1 << " ";
            b--;
        }
        if (x == 0 && y == 1 && c > 0)
        {
            cout << i + 1 << " ";
            c--;
        }
        if (x == 0 && y == 0 && d > 0)
        {
            cout << i + 1 << " ";
            d--;
        }
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string stA;
    cin >> stA;
    string stB;
    cin >> stB;
    for(int i = 0; i < n; i++) {
        int x = stA[i] - '0';
        int y = stB[i] - '0';
        cnt[x][y]++;
    } 
    int flag = -1, need = n / 2;
    for(int clown = 0; clown <= need; clown++) {
       // cout << clown << " ....." << endl;
        for(int i = 0; i <= cnt[1][1] && i <= clown; i++) {
            int a, b, c, d;
            a = i; b = min(clown - a, cnt[1][0]);
            int u, v, w, x;
            u = cnt[1][1] - a; v = cnt[1][0] - b;
            w = max(0, min(clown - u, cnt[0][1])); c = cnt[0][1] - w;
          //  cout << a << " .. " << b << " .. " << c << endl;
            if(a + b == u + w && a + b + c <= need && u + v + w <= need) {
                d = need - (a + b + c);
                flag = 1;
                fun(stA, stB, n, a, b, c, d);
            }

            if(flag == 1) break;
        }
        if(flag == 1) break;
    }
    if(flag == -1) cout << flag << endl;
    return 0;
}
