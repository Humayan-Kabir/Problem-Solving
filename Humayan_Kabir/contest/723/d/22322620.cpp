#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int vis[55][55],grid[55][55],r,c,connected,k,cell=0,z,a;
struct st{
 int x,y,val;
};
bool compare(const st &a,const st &b){
 return a.val<b.val;
}

bool is_ongrid(int m,int n){
return (m>=0 && m<r && n>=0 && n<c);
}
bool is_onborder(int m,int n){
return (m==0 || m==r-1 || n==c-1 || n==0);
}


int fx[4]={-1,0,1,0};
int fy[4]={0,1,0,-1};

void bfs(int m,int n){
vis[m][n]=1;
connected++;
int z=0;
queue<pair<int,int> > Q;
Q.push(make_pair(m,n));
while (!Q.empty())
{
   pii u=Q.front();
   Q.pop();
   for (int i=0;i<4 ;i++ )
   {
      int x,y;
      x=u.first+fx[i];
      y=u.second+fy[i];
      if(is_ongrid(x,y) && vis[x][y]==0 && grid[x][y]==1){
        ///cout<<x<<" "<<y<<endl;
        vis[x][y]=1;
        Q.push(make_pair(x,y));
        connected++;
         if(is_onborder(x,y)){
            z=1;
            ///connected=0;
             ///cout<<"ok"<<" "<<connected<<" Z"<<z;
        }
      }
   }
}
if(z==1) connected=0;
}
void bfs2(int m,int n){
vis[m][n]=1;
grid[m][n]=0;
cell++;
queue<pair<int,int> > Q;
Q.push(make_pair(m,n));
while (!Q.empty())
{
   pii u=Q.front();
   Q.pop();
   for (int i=0;i<4 ;i++ )
   {
      int x,y;
      x=u.first+fx[i];
      y=u.second+fy[i];
      if(is_ongrid(x,y) && vis[x][y]==0 && grid[x][y]==1){
        vis[x][y]=1;
        grid[x][y]=0;
       // cout<<"ok"<<endl;
        Q.push(make_pair(x,y));
        connected++;
        cell++;
      }
   }
}
}

int main()
{
   int i,j,k,sz;
   string str;
   while (scanf("%d%d%d",&r,&c,&k)!=EOF)
   {
      getchar();
      memset(vis,0,sizeof vis);
      for (i=0;i<r ;i++ )
      {
         getline(cin,str);
         for (j=0;j<c ;j++ )
         {
            if(str[j]=='*')
             grid[i][j]=0;
            else
             grid[i][j]=1;
         }
      }
      vector<st> structure;
      for (i=1;i<r-1 ;i++ )
      {
         for (j=1;j<c-1 ;j++ )
         {
            if(grid[i][j]==1 && vis[i][j]==0){
               connected=0;
               bfs(i,j);
             /// cout<<i<<"for loop "<<j<<" "<<connected<<endl;
               st struc;
               struc.x=i;
               struc.y=j;
               struc.val=connected;
               if(connected>0){
                 structure.push_back(struc);
                /// cout<<"size"<<endl;
               }

          }
         }
      }
     sort(structure.begin(),structure.end(),compare);
     sz=structure.size();
    // cout<<sz<<endl;
     memset(vis,0,sizeof vis);
     cell=0;
     for (i=0;i<sz-k ;i++ )
     {
        bfs2(structure[i].x,structure[i].y);
     }
     printf("%d\n",cell);
     for (i=0;i<r ;i++ )
     {
        for (j=0;j<c ;j++ )
        {
           if(grid[i][j]==0)
            printf("*");
           else
            printf(".");
        }
        printf("\n");
     }

   }

  return 0;
}
