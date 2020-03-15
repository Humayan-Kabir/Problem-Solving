/*input
5 5
*/
#include <bits/stdc++.h>
using namespace std;
int vis[2][1003][1003];
double dp[2][1003][1003];
double rec(int w, int b, int ply)
{
	if(w==0 && !ply) return 0;
	if(b==0) return ply == 0; 

	if(vis[ply][w][b]) return dp[ply][w][b];
	vis[ply][w][b] = 1;

	double ret = 0.0;
	double white = 1.0 * w / (w + b);
	double black = 1.0 - white;

	if(!ply)
	{
		ret = white + black * rec(w,b-1,!ply);
	}
	else
	{
		double W = 1.0 * (w) / (w + b - 1);
		double B = 1.0 * (b - 1) / (w + b - 1);
		if(b > 1)
			ret+= black * B * rec(w, b - 2, !ply);
		ret += black * W * rec(w - 1, b - 1, !ply);
	}

	return dp[ply][w][b] = ret;
}
int main(int argc, char const *argv[])
{
	int w,b;
	cin >> w >> b;	
	cout << fixed << setprecision(12) << rec(w,b,0) << endl;
	return 0;
}