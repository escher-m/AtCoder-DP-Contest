#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll findmaxval(ll weight[],ll value[], int w, int n)
{
	ll maxval[n+1][w+1];
	//maxval[x][y]=max value that can be generated from 1 to x items that weigh a max of y kg.
	// answer=maxval[n][w]
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(j==0 || i==0)
			{
				maxval[i][j]=0;
			}
            else
            {
                if(weight[i]>j)
    			{
    				maxval[i][j]=maxval[i-1][j];
    			}
    			else
    			{
    				maxval[i][j]=max(maxval[i-1][j], value[i]+maxval[i-1][j-weight[i]]);
    			}
            }
			
		}
	}
	return maxval[n][w];
	
}
int main()
{
	int n,w;
	cin>>n>>w;
	ll weight[n],value[n];
	for(int i=1;i<=n;i++)
	{
		cin>>weight[i]>>value[i];
	}
	//Problem: find the max value from n items with W weight
	//Subproblem: find the max value from 1 to i items with j weight.
	// if i know the max value from i-1 items with jx weight .

	
	cout<<findmaxval(weight, value, w,n);
}
