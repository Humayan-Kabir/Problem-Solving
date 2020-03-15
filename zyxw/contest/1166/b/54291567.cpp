#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int k, x, y, flag = 0;
    cin >> k;
    for(int i = 1; i <= k; i++) {
        if(k % i == 0) {
            x = k / i; y = i;
            if(x>=5 && y>=5) {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0) {
        cout << -1 << endl;
        return 0;
    }
    vector<string> vowel;
    vowel.push_back("aeiou");
    vowel.push_back("eioua");
    vowel.push_back("iouae");
    vowel.push_back("ouaei");
    vowel.push_back("uaeio");
    char grid[x + 1][y + 1];
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(j < 5) {
                grid[i][j] = vowel[i % 5][j];
            }
            if(j >= 5) {
                grid[i][j] = vowel[0][i % 5];
            }
        }
    }
    string ans = "";
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
          ans += grid[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
