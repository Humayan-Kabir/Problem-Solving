#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    vector< pair<int,int> > vt;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        vt.push_back({l,-1});
        vt.push_back({r,1});
    }

    int cnt=0,foo=1;
    sort(vt.begin(),vt.end());
    for(int i=0;i<vt.size();i++)
    {
        cnt+=vt[i].second;
        if(cnt<-2) foo=0;
    }

    if(foo) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}