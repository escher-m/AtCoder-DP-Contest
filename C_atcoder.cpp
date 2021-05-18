#include<bits/stdc++.h>
using namespace std;

int find_happiness(int happy[][3], int n, int points[][3])
{

	for(int i=1;i<=n;i++)
	{
		
		points[i][0]=happy[i][0]+max(points[i-1][1],points[i-1][2]);
		points[i][1]=happy[i][1]+max(points[i-1][0],points[i-1][2]);
		points[i][2]=happy[i][2]+max(points[i-1][0],points[i-1][1]);
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
	//SUBPROBLEM: if i know the max happiness from day 1 till day i-1 for each activity on day i-1, can i find the max happiness on day i for each activity
	
	//array points: make it a 2d array with 3 columns and store 3 max for each activity
	//answer=max(points[n][0],max(point[n][1],point[n][2]);

	int points[n+1][3];
	memset(points, 0, sizeof(points[0][0])*(n+1)*3);
	cout<<find_happiness(happy, n, points);
}
