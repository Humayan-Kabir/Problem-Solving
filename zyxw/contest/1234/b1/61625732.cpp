#include<bits/stdc++.h>
#define mx 100007
#define mod 1000000007
using namespace std;
typedef long long int LL;
deque<int> DQ;
multiset<int> maping;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if(maping.find(num) != maping.end()) {
            continue;
        }
        else {
            if(DQ.size() == k) {
                int u = DQ.back();
                DQ.pop_back();
                maping.erase(maping.find(u));
                DQ.push_front(num);
                maping.insert(num);
            }
            else {
                maping.insert(num);
                DQ.push_front(num);
            }
        }
    }
    cout << DQ.size() << endl;
    for(int v : DQ) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
