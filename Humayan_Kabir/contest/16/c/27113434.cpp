#include<bits/stdc++.h>
using namespace std;
typedef long long int LLI;
int main()
{
    LLI a,b,x,y;

    cin>>a>>b>>x>>y;

    LLI gcd=__gcd(x,y);

    x/=gcd; y/=gcd;

    LLI low=1,high=2000000000;

    LLI u=0,v=0;

    while (low<=high)
    {
       LLI mid=(low+high)/2;

       LLI m=x*mid,n=y*mid;

       if(m>a || n>b)
       {
           high=mid-1;
       }
       else
       {
           u=mid*x; v=mid*y;
           low=mid+1;
       }
    }

    cout<<u<<" "<<v<<endl;

    return 0;
}