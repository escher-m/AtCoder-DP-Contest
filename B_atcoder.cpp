#include <bits/stdc++.h>

using namespace std;
#define ll long long 

int find_cost(int height[], int n, int k, int cost[])
{
	for(int i=1;i<n+1;i++)
	{
		if(i==1)
		{
			cost[i]=0;
		}
		else
		{
		  for(int j=i-1;j>=max(1,i-k);j--)
		  {
		  	cost[i]=min(cost[i],cost[j]+abs(height[j]-height[i]));
		  }
		}
	}

	return cost[n];
}
int main()
{
	int n,k;
	cin>>n>>k;

	int height[n+1];
	height[0]=INT_MAX;
	for (int i=1;i<n+1;i++)
	{
		cin>>height[i];
	}
	
//subproblem: what is the min cost 1 thru i if i know the min cost from 1 thru i-1
//every array element can store the min cost required to reach it
//lets create an array which includes the min cost uptil that index
	int cost[n+1];
	std::fill_n (cost, n+1, INT_MAX);
	cost[1]=0;

    cout<<find_cost(height, n, k, cost);
}