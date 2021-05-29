#include <bits/stdc++.h>
using namespace std;

#define ll long long 

stack<char> lcs; 
string m,n;
int find_lcs(string m, string n, int lm, int ln)
{
	int dp[lm+1][ln+1];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<=lm;i++)
	{
		for(int j=0;j<=ln;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
			}
			else if(m[i-1]==n[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				//return 1+find_lcs(m, n, lm-1, ln-1);
			}
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				//return max(find_lcs(m,n,lm,ln-1),find_lcs(m,n,lm-1,ln));
			}
		}
	}
	int i=lm,j=ln;
	while(i>0&&j>0)
	{
		if(m[i-1]==n[j-1])
		{
			lcs.push(m[i-1]);
			i--;
			j--;
		}
		else
		{
			if(dp[i][j-1]>dp[i-1][j])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	
	return dp[lm][ln];
}

int main()
{
	//string m, n;
	cin>>m>>n;
	int lm=m.length();
	//cout<<lm<<' ';
	int ln=n.length();
	//cout<<ln<<endl;
	//stack<char> lcs;

	//Problem: find the length of the longest common subsequence
	//Subproblem: if i know lcs length from 1 to (i-1)th and 1 to (j-1)-th index of the strings
	// can i find the lcs length from 1 to ith and 1 to j-th index

	int lcs_length=find_lcs(m,n,lm,ln);
	while(!lcs.empty())
	{
		cout<<lcs.top();
		lcs.pop();
	}
	cout<<endl;
}