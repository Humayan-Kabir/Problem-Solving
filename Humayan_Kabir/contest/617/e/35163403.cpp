/*input
6 2 3
1 2 1 1 0 3
1 6
3 5
*/
#include<bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
int BlockSize = 316, k, ara[mx], pref[mx], cnt[1<<20];
LL result = 0, ans[1<<20];
struct Query
{
    int left, right, id;
    Query(int left,int right,int id) {
        this->left = left, this->right = right, this->id = id;
    }
    bool operator < (const Query other) const {
        return right < other.right;
    }
};
inline void add(int v)
{
    result+=cnt[v ^ k];
    cnt[v]++;
}
inline void del(int v)
{
    cnt[v]--;
    result-=cnt[v ^ k];
}
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1; i<=n; i++)
    {
        scanf("%d",ara + i);
        pref[i] = pref[i - 1] ^ ara[i];
    }
    vector< vector<Query> > blocks(n / BlockSize + 2, vector<Query>());
    for(int i = 0; i<m; i++)
    {
        int left, right;
        scanf("%d %d",&left,&right);
        left--,right++;
        blocks[left/BlockSize].push_back(Query(left,right,i));
    }
    for(auto &v : blocks)
    {
        sort(v.begin(), v.end());
    }
    for(int i = 0; i<blocks.size(); i++)
    {
        int left, right;
        left = right = i * BlockSize;
        for(auto &q: blocks[i])
        {
            while(right < q.right)
            {
                add(pref[right]);
                right++;
            }
            while(left < q.left)
            {
                del(pref[left]);
                left++;
            }
            while(left > q.left)
            {
                left--;
                add(pref[left]);
            }
            ans[q.id] = result;
        }
        for(int j = left; j<right; j++)
        {
            del(pref[j]);
        }
    }
    for(int i = 0; i<m; i++)
    {
        printf("%lld\n",ans[i]);
    }
    return 0;
}
