#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
std::vector<PII> vt[3*100007];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    std::vector<PII> point;
    map<PII, int> mymap;
    int n,indx=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        vector<int> v;
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        point.push_back(make_pair(v[0],v[1]));
        if(mymap.find(make_pair(v[0],v[1]))==mymap.end())
        {
            mymap[make_pair(v[0],v[1])]=indx++;
        }
        int pos=mymap[make_pair(v[0],v[1])];
        vt[pos].push_back(make_pair(v[2],i));
        point.push_back(make_pair(v[0],v[2]));
        if(mymap.find(make_pair(v[0],v[2]))==mymap.end())
        {
            mymap[make_pair(v[0],v[2])]=indx++;
        }
        pos=mymap[make_pair(v[0],v[2])];
        vt[pos].push_back(make_pair(v[1],i));
        point.push_back(make_pair(v[1],v[2]));
        if(mymap.find(make_pair(v[1],v[2]))==mymap.end())
        {
           mymap[make_pair(v[1],v[2])]=indx++;
        }
        pos=mymap[make_pair(v[1],v[2])];
        vt[pos].push_back(make_pair(v[0],i));

    }
    for(int i=0; i<indx; i++)
    {
        sort(vt[i].begin(),vt[i].end());
    }
    long long int line1,line2,rad=0;
    for(int i=0; i<point.size(); i++)
    {
        int x,y,radii;
        x=point[i].first;
        y=point[i].second;
        int pos=mymap[make_pair(x,y)];
        int sz=vt[pos].size();
       // cout<<x<<" start "<<y<<endl;
        if(sz>1)
        {
            radii=min(x,y);
            radii=min(radii,vt[pos][sz-1].first+vt[pos][sz-2].first);
            //cout<<radii<<"..this is.."<<endl;
            if(rad<radii)
            {
                rad=radii;
                line1=vt[pos][sz-1].second;
                line2=vt[pos][sz-2].second;
            }
        }
        else
        {
            radii=min(min(x,y),vt[pos][sz-1].first);
            if(rad<radii)
            {
                rad=radii;
                line1=vt[pos][sz-1].second;
                line2=0;
            }
        }
    }
    if(line2==0 || (line1==line2))
    {
        cout<<1<<endl;
        cout<<line1<<endl;
    }
    else
    {
        cout<<2<<endl;
        cout<<line1<<" "<<line2<<endl;
    }
    return 0;
}
