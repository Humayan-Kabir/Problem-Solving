#include<bits/stdc++.h>
using namespace std;
int main()
{
    string st1,st2;
    cin>>st1;
    cin>>st2;
    map<char,char> mymap;
    for(int i=0;i<26;i++)
    {
        mymap[st1[i]]=st2[i];
    }

    string ans;

    string ss;
    cin>>ss;
    for(int i=0;i<ss.size();i++)
    {
        if(isalpha(ss[i]))
        {
            if(isupper(ss[i]))
            {
                char ch=tolower(ss[i]);
                char t=mymap[ch];
                t=toupper(t);
                ans+=t;
            }
            else {
                char t=mymap[ss[i]];
                ans+=t;
            }
        }
        else ans+=ss[i];
    }

    cout<<ans<<endl;

    return 0;
}
