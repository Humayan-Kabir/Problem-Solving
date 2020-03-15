#include "bits/stdc++.h"
using namespace std;
int vis[200];
int main()
{
    int n,left[200],right[200];
    cin>>n;
    vector<int> edge,vt;
    for(int i=1; i<=n; i++)
    {
        cin>>left[i];
        cin>>right[i];
        if(left[i]==0 && right[i]!=0) edge.push_back(i);
        else if(left[i]==0 && right[i]==0) vt.push_back(i);
    }
    int foo=0;
    int prev,siz=edge.size()-1;
    for(int i=0; i<edge.size(); i++)
    {
        foo=1;
        int now=edge[i];
        while (1)
        {
            int tem=now;
            prev=tem;
            now=right[now];
            if(now==0 && i!=siz)
            {
                right[tem]=edge[i+1];
                left[edge[i+1]]=tem;
                break;
            }
            else if(now==0) break;
        }
    }
    for(int i=0; i<vt.size(); i++)
    {
        int now=vt[i];
        if(foo)
        {
            right[prev]=now;
            left[now]=prev;
            prev=now;
        }
        else
        {
            if(i==0) continue;
            else
            {
                left[now]=vt[i-1];
                right[vt[i-1]]=now;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<left[i]<<" "<<right[i]<<endl;
    }
    return 0;
}
