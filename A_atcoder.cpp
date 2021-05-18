#include <bits/stdc++.h>

using namespace std;
#define ll long long 

//find_cost(int[], int, int)
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
		  //  int c1=height[i]-height[i-1];
		  //  int c2=fabs(height[i]-height[i-2]);
		  //  cout<<"\n"<<c1<<"\t"<<c2;
			cost[i]=min(cost[i-1]+fabs(height[i]-height[i-1]),cost[i-2]+fabs(height[i]-height[i-2]));
			//cout<<"\n"<<cost[i];
		}
	}
// 	for(int i=0;i<n+1;i++)
// 	{
// 		cout<<cost[i]<<" ";
// 	}
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

//memset(cost,INT_MAX,n+1);
//cost[0]=-1;
cost[1]=0;
//answer=cost[n];
// for(int i=0;i<n+1;i++)
// 	{
// 		cout<<cost[i]<<" ";
// 	}
    cout<<find_cost(height, n, cost);

}