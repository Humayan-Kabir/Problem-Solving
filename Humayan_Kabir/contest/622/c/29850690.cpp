#include<bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false); 
   int ara[200007];
   int n,q;
   cin>>n>>q;
   for(int i=1;i<=n;i++) cin>>ara[i];
   int suffix[200007];
   for(int i=n;i>=1;i--)
   {
       if(i==n) suffix[i]=i;
       else if(ara[i]==ara[i+1]) suffix[i]=suffix[i+1];
       else suffix[i]=i;
   }
   while (q--)
   {
       int l,r,val;
       cin>>l>>r>>val;
       if(ara[l]!=val) cout<<l<<endl;
       else if(suffix[l]>=r) cout<<-1<<endl;
       else cout<<suffix[l]+1<<endl;
   }
    return 0;
}
