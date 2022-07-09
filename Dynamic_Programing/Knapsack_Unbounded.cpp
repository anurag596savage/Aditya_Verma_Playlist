#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[10000][1000];

int Knapsack_Unbounded_DP(int wt[],int val[],int n,int W)
{
	for(int i=0;i<=W;i++)
	{
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0] = 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(wt[i-1]<=j)
			{
				dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
			}
		}
	}
	
	return dp[n][W];
}

int Knapsack_Unbounded_Recursive(int wt[],int val[],int n,int W)
{
	if(n==0 || W==0)
	{
		return 0;
	}
	if(wt[n-1]<=W)
	{
		return max(val[n-1]+Knapsack_Unbounded_Recursive(wt,val,n,W-wt[n-1]),
			Knapsack_Unbounded_Recursive(wt,val,n-1,W));
	}
	else if(wt[n-1]>W)
	{
		return Knapsack_Unbounded_Recursive(wt,val,n-1,W);
	}
}

int main()
{
	int n;
	cin>>n;
	
	int wt[n],val[n];
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	
	int W;
	cin>>W;
	
	/*
	
	--------------------Recursive-----------------------
	
	cout<<Knapsack_Unbounded_Recursive(wt,val,n,W)<<endl;
	
	
	*/
	
	cout<<Knapsack_Unbounded_DP(wt,val,n,W)<<endl;
	
	return 0;
}

