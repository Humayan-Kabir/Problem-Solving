/*input
1 2
ab
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int endmark;
	node* next[26];
	node()
	{
		endmark = false;
		for(int i = 0; i<26; i++)
			next[i] = NULL;
	} 
} *root;
inline void insert(char *str,int len)
{
	node* current = root;
	for(int i = 0; i<len; i++)
	{
		int id = str[i] - 'a';
		if(current -> next[id] == NULL)
			current -> next[id] = new node();
		current = current -> next[id];
	}
	current -> endmark = true;
}
inline int search(char *str,int len)
{
	node* current = root;
	for(int i = 0; i<len; i++)
	{
		int id = str[i] - 'a';
		if(current -> next[id] == NULL)
			return false;
		current = current -> next[id];
	}
	return current -> endmark; 
}
inline void del(node *current)
{
	for(int i = 0; i<26; i++) 
		if(current -> next[i])
			del(current -> next[i]);
	delete(current);	
}
inline bool CanWin(node *current,int now)
{
	for(int i = 0; i<26; i++)
	{
		if(current -> next[i]  && !CanWin(current -> next[i],now))
			return true;
	}
	return false;
}
int CanLose(node* current)
{
	int opt = true;
	for(int id = 0; id<26; id++)
	{
		if(current -> next[id] != NULL && !CanLose(current -> next[id]))
			return true;
		else if(current -> next[id] != NULL)
			opt = false;
	}
	return opt;
}
int main(int argc, char const *argv[])
{
	root = new node();
	int n,k;
	cin >> n >> k;
	for(int i = 1; i<=n; i++)
	{
		char str[100007];
		scanf("%s",str);
		insert(str,strlen(str));
	}
	int win = CanWin(root,1);
	int lose = CanLose(root);
	//cout << win << " "<<lose<<endl;
	if(win && !lose)
	{
		if(k&1) cout <<"First"<<endl;
		else cout<<"Second"<<endl;
	}
	else if(win && lose) cout <<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}