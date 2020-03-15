#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int node,edge;
    cin>>node>>edge;
    stack<int> vt[node+2];
    stack<int> dummy[node+2];
    for(int i=1; i<=node; i++)
    {
        int dis;
        cin>>dis;
        vt[dis].push(i);
        dummy[dis].push(i);
    }
    int flag=1,counter=0;
    for(int i=0; i<node; i++)
    {
        if(i>=1)
        {
            int p=vt[i].size();
            int q=vt[i-1].size();
            int need;
            if(i-1>=1)
             need=(p+q)/q;
            else need=(p+q-1)/q;
            if(need>edge)
            {
                flag=0;
                break;
            }
        }
        if(vt[i].size()==0 && counter<node)
        {
            flag=0;
            break;
        }
        counter+=vt[i].size();
        if(counter==node) break;
    }
    if(flag==0 || vt[0].size()>1)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<node-1<<endl;
    while (!dummy[1].empty())
    {
       cout<<vt[0].top()<<" "<<dummy[1].top()<<endl;
       dummy[1].pop();
    }
    counter=1+vt[1].size();
    for(int i=1; i<node-1; i++)

    {
       while (!vt[i].empty())
       {
          int u=vt[i].top();
          vt[i].pop();
          int fl=0;
          while (!dummy[i+1].empty())
          {
             if(fl==edge-1) break;
             int v=dummy[i+1].top();
             dummy[i+1].pop();
             fl++;
             cout<<u<<" "<<v<<endl;
             counter++;

          }
          if(counter==node) break;
       }
       if(counter==node) break;
    }

    return 0;
}
