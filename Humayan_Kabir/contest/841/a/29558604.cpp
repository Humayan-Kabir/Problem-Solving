#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n,k;
    cin>>n>>k;
    int ara[30];
    memset(ara,0,sizeof ara);
    string st;
    cin>>st;
    for(int i=0;i<st.size();i++)
    {
        ara[(st[i]-'a')]++;
    }
    int foo=1;

    for(int i=0;i<26;i++)
    {
        int x=ara[i];
        int y=(x+k-1)/k;
        if(y>=2) foo=0;
    }

    if(foo) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
