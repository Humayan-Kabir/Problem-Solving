/*input
5 5
*/
#include <bits/stdc++.h>
using namespace std;
double dp[1003][1003];
int vis[1003][1003];
double rec(int w,int b)
{
	if(w<=0) return 0.0;
	if(b<=0) return 1.0;
	if(vis[w][b]) return dp[w][b];
	vis[w][b] = 1;
	int x = w, y = b;
	double ret = w * 1.0 / (w + b);
	double cont_prob = b * 1.0 / (w + b);
	b--;
	cont_prob *= b * 1.0 / (w + b);
	b--;
	if(cont_prob > 1e-13)
        {
	double black = rec(w,b-1) * (b * 1.0 / (w + b));
	double white = rec(w-1,b) * (w * 1.0 / (w +b));
	ret += cont_prob * (black + white);
        }
	
	return dp[x][y] = ret;
}
int main(int argc, char const *argv[])
{
	int white,black;
	cin >> white >> black;
	cout<<fixed<<setprecision(12)<<rec(white,black)<<endl;
	return 0;
}