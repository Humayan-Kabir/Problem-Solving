#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main()
{
        int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%4==1)
        {
            printf("a");
        }
        else if(i%4==2 || i%4==3)
        {
            printf("b");
        }
        else printf("a");
    }
    printf("\n");
    return 0;
}
