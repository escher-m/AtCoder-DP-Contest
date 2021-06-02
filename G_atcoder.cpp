#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int M= 1e5+10;
int dp[M];
int visited[M]={0};

vector<int> adj[M];
int dfs(int startV)
	{
		if(visited[startV]==1)
		{
		    return dp[startV];
		}
		visited[startV]=1;
		int path_length=0;
		vector<int>::iterator j;
		for(j=adj[startV].begin();j!=adj[startV].end();j++)
		{
			path_length=max(path_length,dfs(*j)+1);
		}
		dp[startV]=path_length;
		return dp[startV];
	}
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
	}
	//Idea: Use DFS on every vertex and store the max path from that vertex. return the max.
	//array path[V] stores max length
	//answer: max element in path
    int ans=0;
    int path[n];
	for(int i=0;i<n;i++)
	{
		path[i]=dfs(i+1);
		if(path[i]>ans)
		{
			ans=path[i];
		}
	}

	cout<<ans<<endl;
}
