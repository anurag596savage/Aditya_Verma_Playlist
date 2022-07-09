#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Maximum_Ways_of_Coin_Change_DP(int arr[],int n,int sum)
{
	for(int i=0;i<=sum;i++)
	{
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j] = dp[i-1][j]+dp[i][j-arr[i-1]];
			}
			else if(arr[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}

int Maximum_Ways_of_Coin_Change_Recursive(int arr[],int n,int sum)
{
	if(sum==0)
	{
		return 1;
	}
	if(n==0)
	{
		return 0;
	}
	
	if(arr[n-1]<=sum)
	{
		return Maximum_Ways_of_Coin_Change_Recursive(arr,n,sum-arr[n-1]) +
		Maximum_Ways_of_Coin_Change_Recursive(arr,n-1,sum);
		
	}
	else if(arr[n-1]>sum)
	{
		return Maximum_Ways_of_Coin_Change_Recursive(arr,n-1,sum);
	}
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int sum;
	cin>>sum;
	
	/*
	
	----------------------Recursive-----------------------------
	
	cout<<Maximum_Ways_of_Coin_Change_Recursive(arr,n,sum)<<endl;
	
	
	*/
	
	cout<<Maximum_Ways_of_Coin_Change_DP(arr,n,sum)<<endl;
	
	return 0;
}

