#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string st;
    cin>>st;
    vector<int> pos;
    pos.push_back(0);
    int mn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(st[i]=='0') pos.push_back(i+1);
    }
    int sz=pos.size()-1;
    for(int i=k+1;i<=sz;i++)
    {
       int Find=(pos[i]+pos[i-k])/2;
       int p=lower_bound(pos.begin(),pos.end(),Find)-pos.begin();
       int q=i-k;
       int dis=min(max(abs(pos[i]-pos[p]),abs(pos[q]-pos[p])),max(abs(pos[i]-pos[p-1]),abs(pos[q]-pos[p-1])));
       mn=min(mn,dis);
    }
    cout<<mn<<endl;
    return 0;

}
