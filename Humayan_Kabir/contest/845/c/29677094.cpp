#include<bits/stdc++.h>

using namespace std;

struct st
{
    int l,r;
    bool operator <(const st &p) const{
        if(l==p.l) return r<p.r;
        return l<p.l;
    }
};

int main()
{
    vector<st>vt;
    int n;
    cin >> n;
    for(int i=0 ;i<n ; i++)
    {
        st x;
        scanf("%d %d",&x.l,&x.r);
        vt.push_back(x);
    }
    int cnt = 1;
    sort(vt.begin(),vt.end());
    int r1 = vt[0].r,r2 = -1;
    for(int i=1;i<vt.size();i++)
    {
        if(vt[i].l>r1)
        {
            cnt++;
            r1 = vt[i].r;
        }
        else if(vt[i].l>r2)
        {
            cnt++;
            r2 = vt[i].r;
        }
    }
    if(cnt==n) cout << "YES" << endl;
    else cout << "NO" << endl;
}