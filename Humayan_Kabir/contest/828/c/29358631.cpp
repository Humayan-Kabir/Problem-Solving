#include<bits/stdc++.h>
using namespace std;
char ch[2000007];
bool bol[2000007];
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    for(int i=1;i<=2000000;i++) s.insert(i);
    set<int> ::iterator it;
    int n,maximum=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        int siz=st.length();
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int pos;
            cin>>pos;
            maximum=max(maximum,pos+siz-1);
            std::vector<int> del;
            for(it=s.upper_bound(pos-1);it!=s.end();it++)
            {
                int p=*it;

                if((p-pos+1)>siz) break;

                ch[p]=st[p-pos];

                bol[p]=1;

                del.push_back(p);

            }

            for(int j=0;j<del.size();j++)
            {
                it=s.find(del[j]);
                s.erase(it);
            }
        }
    }

    string ans;

    for(int i=1;i<=maximum;i++)
    {
        if(bol[i]) ans+=ch[i];
        else ans+='a';
    }

    cout<<ans<<endl;

    return 0;
}