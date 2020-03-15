#include<bits/stdc++.h>
using namespace std;
int r,c,grid[600][600],connected=0,k,dot;
bool out_ofgrid(int m,int n)
{
    return (m<0 || m>=r || n<0 || n>=c);
}
void dfs(int m,int n)
{
    if(out_ofgrid(m,n))
        return;
    if(grid[m][n]!=0 || connected+k==dot)
        return;
    connected++;
    grid[m][n]=-1;
    dfs(m,n+1);
    dfs(m,n-1);
    dfs(m-1,n);
    dfs(m+1,n);
    return;
}
int main()
{
    int i,j,x,y,n;
    string str;
    while (cin>>r>>c>>k)
    {
        getchar();
        dot=0;
        for (i=0; i<r ; i++ )
        {
            getline(cin,str);
            for (j=0; j<c ; j++ )
            {
                if(str[j]=='.')
                {
                    grid[i][j]=0;
                    x=i;
                    y=j;
                    dot++;
                }
                else
                    grid[i][j]=1;
            }
        }

    connected=0;
    //memset(vis,0,sizeof vis);
    dfs(x,y);
    for (i=0; i<r ; i++ )
    {
        for (j=0; j<c ; j++ )
        {
            if(grid[i][j]==0)
                printf("X");
            else if(grid[i][j]==-1)
                printf(".");
            else
                printf("#");

        }
        printf("\n");

    }


}
    return 0;
}
