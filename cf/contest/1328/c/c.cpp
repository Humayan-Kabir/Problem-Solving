/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-03-26 20:39:02
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
string a;
string b;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        a = "1"; b = "1";
        int len = str.length(), comp = 0;
        for(int i = 1; i < len; i++) {
            if(str[i] == '0') {
                a += '0';
                b += '0';
            }
            if(str[i] == '1') {
                if(comp == 0) {
                    a += '0';
                    b += '1';
                    comp = -1;
                }
                else if(comp == -1) {
                    a += '1';
                    b += '0';
                }
                else if(comp == 1) {
                    a += '0';
                    b += '1';
                }
            }
            if(str[i] == '2') {
                    // cout << " .... " << i << endl;
                if(comp == 0) {
                    a += '1';
                    b += '1';
                }
                else if(comp == -1) {
                    a += '2';
                    b += '0';
                } 
                else if(comp == 1) {
                    a += '0';
                    b += '2';
                }
            }
        }
        cout << a << endl;
        cout << b << endl;
        a = "";
        b = "";
    }
    return 0;
}