#include<bits/stdc++.h>
using namespace std;

int find_happiness(int happy[][3], int n, int points[][3])
{
// 	points[0][0]=0;
// 	points[0][1]=0;
// 	points[0][2]=0;
	for(int i=1;i<=n;i++)
	{
		
		points[i][0]=happy[i][0]+max(points[i-1][1],points[i-1][2]);
		//cout<<points[i][0]<<'\t';
		points[i][1]=happy[i][1]+max(points[i-1][0],points[i-1][2]);
		//cout<<points[i][1]<<'\t';
		points[i][2]=happy[i][2]+max(points[i-1][0],points[i-1][1]);
		//cout<<points[i][2]<<'\t'<<endl;

		// //int val=act[i-1];
		// for(int j=0;j<3;j++)
		// {
		// 	points[i][j]=happy[i][j]+max(points[i-1][])

		// 	if(j!=val)
		// 	{
		// 		int p1=points[i]; 
		// 		points[i]=max(points[i], points[i-1]+happy[i][j]);
		// 		int p2=points[i];
		// 		if(p1!=p2)
		// 		{
		// 			val=j;
		// 		}
		// 	}	
		// }
		// act[i]=val;
	}
	return max(points[n][0],max(points[n][1],points[n][2]));
}

int main()
{
	int n;
	cin>>n;
	int happy[n+1][3];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>happy[i][j];
		}
	}
	//SUBPROBLEM: if i know the max happiness from day 1 till day i-1, and the activity done on day i-1 
	// can i find the happiness on day i
	//option of backtracking
		//instead of having the max for i day; record the max of the three activities of i day 
		//the i day's activity might change based on the i-1 day activity values 
		// but the i-th day's individual max value for each activity will remain same.

	// each new day's 3 max account for the 3 max of the i-1 day therefore no need for backtracking 

	//array points where each element will have max points till that day
		//addition: make it a 2d array with 3 columns and store 3 max for each act
	//answer=max(points[n][0],max(point[n][1],point[n][2]);

	//another array would store which activity was done on i-th day 
	int points[n+1][3];
	//int act[n+1];
	memset(points, 0, sizeof(points[0][0])*(n+1)*3);
	//memset(array, -1, sizeof(array[0][0]) * row * count
	//memset(act, -1, n+1);

	//points[0]=-1;
	cout<<find_happiness(happy, n, points);
	//how to find the max happiness on day i
	//points[i]=points[i-1]+max(happy[i][])
}