#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,a,b;
    char str[100009];
    while (scanf("%d%d%d",&n,&a,&b)!=EOF)
    {

        getchar();
        for (i=0; i<n ; i++ )
        {
            scanf("%c",&str[i]);
        }
        if(str[a-1]==str[b-1])
        {
            printf("0\n");
            continue;
        }
        else
        {
           printf("1\n");
        }
    }

    return 0;
}
