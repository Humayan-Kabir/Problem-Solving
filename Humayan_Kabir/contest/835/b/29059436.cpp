#include<bits/stdc++.h>
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long int LL;
int main()
{
    ios_base::sync_with_stdio(false);
    LL k;
    cin>>k;
    vector<int> vt;
    string st;
    cin>>st;
    LL sum=0;
    for(int i=0; i<st.size(); i++)
    {
        vt.push_back((st[i]-'0'));
        sum+=(st[i]-'0');
    }
    if(sum>=k)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(vt.begin(),vt.end());
    int cnt=0;
    for(int i=0; i<vt.size(); i++)
    {
        sum+=(9-vt[i]);
        cnt++;
        if(sum>=k) break;
    }

    cout<<cnt<<endl;

    return 0;
}
