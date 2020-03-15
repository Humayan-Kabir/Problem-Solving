#include<bits/stdc++.h>
using namespace std;
const int N=123456;
typedef long long int LL;
int main()
{
    int n,m;
    cin>>n>>m;

    int fl=0;

    int Grid[120][120];

    int grid[120][120];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
          cin>>Grid[i][j];
          grid[i][j]=Grid[i][j];
        }
    }

    if(n>m)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            grid[j][i]=Grid[i][j];
        }
        swap(n,m);
        fl=1;
    }
    int dummy[n+2][m+2];
    vector<int> vt;
    vt.push_back(0);
    for(int i=1; i<=n; i++)
    {
        int mn=INT_MAX;

        for(int j=1; j<=m; j++)
            mn=min(mn,grid[i][j]);

        vt.push_back(mn);

    }

    for(int i=1; i<=n; i++)
    {

        for(int j=1; j<=m; j++)
        {

            dummy[i][j]=grid[i][j]-vt[i];
        }
    }

    int flag=1;

    for(int j=1; j<=m; j++)
    {
        int p=dummy[1][j];

        for(int i=1; i<=n; i++)
        {
            if(dummy[i][j]!=p)
            {
                flag=0;
                break;
            }
        }
    }

    if(flag==0)
    {
        printf("-1\n");
        return 0;
    }
    else
    {
        int ans=0,ans2=0;
        for(int i=0; i<vt.size(); i++) ans+=vt[i];
        for(int i=1; i<=m; i++) ans+=dummy[1][i];

        cout<<ans<<endl;
        for(int i=1; i<vt.size(); i++)
        {
            for(int j=1; j<=vt[i]; j++)
            {
               if(!fl) printf("row %d\n",i);
               else printf("col %d\n",i);
            }
        }

        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=dummy[1][j]; i++)
            {
                 if(!fl) printf("col %d\n",j);
               else printf("row %d\n",j);
            }
        }

    }

    return 0;
}
