#include "bits/stdc++.h"
using namespace std;
int ara[8];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        for(int j=0;j<st.length();j++)
        {
            if(st[j]=='0') continue;
            else
            {
                ara[j+1]++;
            }

        }
    }
    int ans=0;
    for(int i=1;i<=7;i++) ans=max(ans,ara[i]);
    cout<<ans<<endl;
    return 0;
}
