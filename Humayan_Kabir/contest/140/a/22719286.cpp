#include<bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
int main(){
float n,R,r,ans;
while (cin>>n>>R>>r)
{
   if(n==1){
    if(r<=R){
        cout<<"YES"<<endl;
    }
    else
      cout<<"NO"<<endl;
    continue;
   }
   ans=(R*sin(pi/n))/(1+sin(pi/n));
   //cout<<ans<<endl;
   if(ans>=r)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
}
return 0;
}
