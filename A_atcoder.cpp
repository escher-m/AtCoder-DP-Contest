#include <bits/stdc++.h>

using namespace std;
#define ll long long 

int find_cost(int height[], int n, int cost[])
{
	for(int i=1;i<n+1;i++)
	{
		if(i==1)
		{
			cost[i]=0;
		}
		else
		{
			cost[i]=min(cost[i-1]+fabs(height[i]-height[i-1]),cost[i-2]+fabs(height[i]-height[i-2]));
		}
	}

	return cost[n];
}
int main()
{
	int n;
	cin>>n;
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

    	cout<<find_cost(height, n, cost);

}
