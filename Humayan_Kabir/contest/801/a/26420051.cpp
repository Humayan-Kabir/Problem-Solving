#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[200];
    memset(ara,0,sizeof ara);
    string str;
    cin>>str;
    int ln=str.length();
    int cnt=0;
    for(int i=0;i<ln-1;i++)
    {
        if(str[i]=='V' && str[i+1]=='K' && ara[i]==0 && ara[i+1]==0)
        {
           cnt++;
           ara[i]=1;
           ara[i+1]=1;
        }
    }
    int flag=0;
    for(int i=0;i<ln-1;i++)
    {
        if(ara[i]==0 && ara[i+1]==0 && flag==0)
        {
            if(str[i]=='V')
            {
                cnt++;
                flag=1;
            }
            else if(str[i]=='K' && str[i+1]=='K')
            {
               cnt++;
               flag=1;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
