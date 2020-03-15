#include<bits/stdc++.h>
using namespace std;
int main()
{

    string a;
    string b;
    cin>>a>>b;
    string ans;
    int flag=1;
    int ln=a.length();
    for(int i=0;i<ln;i++)
    {
        if(a[i]==b[i])
        {
          ans+=a[i];
        }
        else if(a[i]!=b[i])
        {
           int x,y;
           x=(a[i]-'a');
           y=(b[i]-'a');
           if(y>x)
           {
               flag=0;
           }
           else
           {
               ans+=b[i];
           }

        }
    }
    if(flag==1)
    cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
