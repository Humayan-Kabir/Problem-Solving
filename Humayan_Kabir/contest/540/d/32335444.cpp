/*input
2 2 2
*/
#include <bits/stdc++.h>
using namespace std;
double dp[110][110][110][3];
int vis[110][110][110][3];
double rec(int rock,int paper,int scissor,int id)
{
	if(!rock && !paper && !scissor) return 0;
	if(rock && !paper && !scissor) return (id == 0);
	if(!rock && paper && !scissor) return (id == 1);
	if(!rock && !paper && scissor) return (id == 2);
	double &ret = dp[rock][paper][scissor][id];
	if(vis[rock][paper][scissor][id]) return ret;
	vis[rock][paper][scissor][id] = 1;
	int denom = rock * paper + paper * scissor + scissor * rock;
	ret = 0;
	if(rock > 0 && paper > 0) ret += rec(rock,paper-1,scissor,id) * rock * paper / denom;
	if(rock > 0 && scissor > 0) ret += rec(rock-1,paper,scissor,id) * rock * scissor / denom;
	if(paper > 0 && scissor > 0) ret += rec(rock,paper,scissor-1,id) * paper * scissor / denom;
	return ret;
}
int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i<3; i++)
    {
    	cout<<fixed<< setprecision(20)<< rec(a,b,c,i) <<endl;
    }
	return 0;
}