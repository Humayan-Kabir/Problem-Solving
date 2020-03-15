#include<bits/stdc++.h>
using namespace std;
#define mx 300007
typedef long long int LL;
map<LL,LL> map1;
map<LL,LL> map2;
 vector<LL> ans;
LL fun(LL x) {
    LL num = 0, last = 0;
    for(int i = 0; i < 64; i++) {
        if(x & (1LL << i)) break;
        num += (1LL << i);
        last = i;
    }
    ans.push_back(last + 1);
    return num;
}
LL fun2(LL x) {
    int last = 0;
    for(int i = 0; i < 64; i++) {
        if((1LL << i) & x) last = i;
    }
    last++;
    ans.push_back(last);
    return (1LL << last) - 1;
}
int main(int argc, char const *argv[])
{
    for(int i = 0; i < 64; i++) {
        LL num = (1LL << i);
        map1[num] = 1LL;
        map2[num - 1] = 1LL;
    }
    LL x;
    cin >> x;
    if(map2.find(x) != map2.end()) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    while(map2.find(x) == map2.end()) {
        cnt++;
        x = x ^ fun2(x);
        if(map2.find(x) != map2.end()) break;
        x++;
        cnt++;
    }
    cout << cnt << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}