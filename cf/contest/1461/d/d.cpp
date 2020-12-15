/* بسم الله الرحمن الرحيم
 * Author: ElderWand
 * Time: 2020-12-11 20:58:28
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
typedef long long int LL;

vector<vector<int>> tree[35 * 100007];
map<LL,int> maping;
int curNode = 0, Timer = 0;

void fun(vector<int> vt) {
    if(vt.size() == 0) return;
    int minElement = INT_MAX;
    int maxElement = INT_MIN;
    LL sum = 0;
    for(int i = 0; i < vt.size(); i++) {
        sum += vt[i];
        minElement = min(minElement, vt[i]);
        maxElement = max(maxElement, vt[i]);
    }
    maping[sum] = Timer;
    if(minElement == maxElement) return;
    LL mid = (minElement + maxElement) / 2LL;
    vector<int> left, right;
    for(int i = 0; i < vt.size(); i++) {
        if(1LL*vt[i] <= mid) left.push_back(vt[i]);
        else right.push_back(vt[i]);
    }
    fun(left); fun(right);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        vector<int> vt(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &vt[i]);
        }
        Timer++;
        fun(vt);
        while(q--) {
            int value;
            scanf("%d", &value);
            if(maping.count(value) && maping[value] == Timer) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    return 0;
}
