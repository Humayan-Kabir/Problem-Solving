#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vt;
    int w[1010],a[1010],f[1010];
    memset(f,0,sizeof f);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        if(!f[a[i]])
        {
            vt.push_back(a[i]);
            f[a[i]]=1;
        }

    }

    int ans=0;

    for(int i=1;i<=m;i++)
    {
        int j=0;
        for(j=0;j<vt.size();j++)
        {
            if(a[i]==vt[j]) break;
            ans+=w[vt[j]];
        }

        while (j>0)
        {
            swap(vt[j],vt[j-1]); j--;
        }

    }

    cout<<ans<<endl;

    return 0;

}
