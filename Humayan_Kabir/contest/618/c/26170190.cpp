#include<bits/stdc++.h>
using namespace std;
struct point
{
    long long int x,y,point_no;
    bool operator<(const point &a) const
    {
        if(x==a.x)
            return y<a.y;
        return x<a.x;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    vector<point> tp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       point p;
       cin>>p.x>>p.y;
       p.point_no=i+1;
       tp.push_back(p);
    }
    sort(tp.begin(),tp.end());
    for(int i=0;i<n-2;i++)
    {
        long long int slope1=(tp[i+1].x-tp[i].x)*(tp[i+2].y-tp[i].y);
        long long int slope2=(tp[i+2].x-tp[i].x)*(tp[i+1].y-tp[i].y);
       if(slope2==slope1) continue;
       else
       {
         cout<<tp[i].point_no<<" "<<tp[i+1].point_no<<" "<<tp[i+2].point_no<<endl;
         break;
       }
    }
    return 0;

}
