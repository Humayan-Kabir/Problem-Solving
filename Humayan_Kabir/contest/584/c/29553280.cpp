#include<bits/stdc++.h>
using namespace std;
char find_char(char a,char b)
{
    for(char ch='a'; ch<='z'; ch++)
        if(ch!=a && ch!=b) return ch;
}
int main()
{
    int n,t;
    cin>>n>>t;
    string a,b;
    cin>>a>>b;
    vector<int> same,different;
    char ans[100007];
    memset(ans,'0',sizeof ans);
    for(int i=0; i<n; i++)
    {
        if(a[i]==b[i]) same.push_back(i);
        else different.push_back(i);
    }

    int x=same.size(),y=different.size();
    if(y>(2*t))
    {
        cout<<-1<<endl;
        return 0;
    }
    if((y+x)<t && y<t)
    {
        cout<<-1<<endl;
        return 0;
    }

    if(y<=t)
    {

        for(int i=0; i<y; i++)
        {
            int p=different[i];
            ans[p]=find_char(a[p],b[p]);
            t--;
        }

        for(int i=0; i<x && t>0; i++)
        {
            int p=same[i];
            ans[p]=find_char(a[p],b[p]);
            t--;
        }
    }
    else
    {
        int l=y-t;
        int r=t-l;
        for(int i=0;i<r; i++)
        {
            int p=different[i];
            ans[p]=find_char(a[p],b[p]);
            t--;
        }
        for(int i=r; i<different.size(); i++)
        {
            int p=different[i];
            if(i&1) ans[p]=a[p];
            else ans[p]=b[p];
        }
    }

    string out;
    for(int i=0; i<n; i++)
    {
        if(ans[i]=='0') out+=a[i];
        else out+=ans[i];
    }

    cout<<out<<endl;

    return 0;
}
