/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-19 23:01:10
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        n = n * 2;
        vector<int> vt(n);
        for(int i = 0; i < n; i++) {
            cin >> vt[i];
        }
        sort(vt.begin(), vt.end());
        int found = 0;
       
        for(int i = 0; i < n - 1; i++) {
            int sum = vt[n - 1] + vt[i];
            debug(sum);
            unordered_map<int,int> maping;
            for(int j = 0; j < n; j++) {
                maping[vt[j]]++;
            }
            maping[vt[i]]--;
            maping[vt[n - 1]]--;
            int count = 2;
            vector<pair<int,int>> ans;
            debug(count);
            int preMaxElement = vt[n - 1];
            for(int j = n - 2; j >= 0; j--) {
                int need = preMaxElement - vt[j];
                int limit = (need == vt[j]) ? 2 : 1;
                if(maping[need] >= limit && maping[vt[j]] >= limit) {
                    maping[need]--;
                    maping[vt[j]]--;
                    count += 2;
                    preMaxElement = max(need, vt[j]);
                    ans.push_back({need, vt[j]});
                }
            }
            if(count == n) {
                found = 1;
                cout << "YES" << endl;
                cout << vt[i] + vt[n - 1] << endl;
                cout << vt[i] << " "<< vt[n - 1] << endl;
                for(auto it : ans) {
                    cout << it.first << " " << it.second << endl;
                }
                break;
            } 
        }
        if(!found)
            cout << "NO" << endl;
        
    }
    return 0;
}
