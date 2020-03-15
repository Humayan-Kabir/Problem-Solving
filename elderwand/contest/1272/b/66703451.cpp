#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
using namespace std;
typedef long long int LL;
int arr[mx], prefix[mx], suffix[mx];
int main() { 
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        map<char,int> maping;
        string str;
        cin >> str;
        for(char ch : str) {
            maping[ch]++;
        }
        int L = min(maping['R'], maping['L']), U = min(maping['U'], maping['D']);
        string ans = "";
        if(L == 0 && U == 0) {
            cout << "0" << endl;
            cout << ans << endl;
            continue;
        }
        if(L == 0) {
            cout << 2 << endl;
            cout << "UD" << endl;
            continue;
        }
        if(U == 0) {
            cout << 2 << endl;
            cout << "LR" << endl;
            continue;
        }
        for(int i = 0; i < L; i++) {
            ans+='L';
        }
        for(int i = 0; i < U; i++) {
            ans+='U';
        }
        for(int i = 0; i < L; i++) {
            ans+='R';
        }
         for(int i = 0; i < U; i++) {
            ans+='D';
        }
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    return 0;
}