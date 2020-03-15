/*input
5
2 19 4 9 24
*/
#include <bits/stdc++.h>
#define mx 1000007
using namespace std;
typedef long long int LL;
struct node
{
	node *left,*right;
	node()
	{
		left = NULL; 
		right = NULL;
	}
} *root;
void insert(LL num)
{
	node *current = root;
	for(int i = 63; i>=0; i--)
	{
		bool bit = num & (1LL << i);
		if(bit)
		{
			if(current->right == NULL)
			{
				current->right = new node();
			}
			current = current->right;
		}
		else
		{
			if(current->left == NULL)
			{
				current->left = new node();
			}
			current = current -> left;
		}
	}
}
LL query(LL num)
{
	LL ans = 0;
	node *current = root;
	for(int i = 63; i>=0; i--)
	{
		bool bit = num & (1LL << i);
		//cout << bit <<"  "<< i << endl;
		if(bit)
		{
			if(current->left != NULL)
			{
				ans = ans | (1LL<<i);
				current = current->left;
			}
			else if(current->right != NULL)
			{
				current = current -> right;
			}
		}
		else 
		{
			if(current -> right != NULL)
			{
				ans = ans | (1LL << i);
				current = current-> right;
			}
			else if(current->left != NULL)
			{
				current = current->left;
			}
		}
	}

	return ans;
}
LL ara[mx];
int main(int argc, char const *argv[])
{
	root = new node();
	int n;
	cin >> n;
	LL Xor = 0;
	insert(Xor);
	for(int i = 1; i<=n; i++)
	{
		cin >> ara[i];
		Xor = Xor ^ ara[i];
		ara[i] = ara[i-1] ^ ara[i];
	}
	LL ans = 0;
	for(int i = 1; i<=n; i++)
	{
		LL now = Xor ^ ara[i-1];
		ans = max(ans,max(ara[i],query(now)));
		insert(ara[i]);
	}
	cout << ans << endl;
	return 0;
}