#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Count_of_Subset_Sum_DP(int arr[],int n,int sum)
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
				dp[i][j] = dp[i-1][j]+dp[i-1][j-arr[i-1]];
			}
			else if(arr[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int Count_of_Subset_Sum_Recursive(int arr[],int n,int sum)
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
		return Count_of_Subset_Sum_Recursive(arr,n-1,sum-arr[n-1])+Count_of_Subset_Sum_Recursive(arr,n-1,sum);
	}
	else if(arr[n-1]>sum)
	{
		return Count_of_Subset_Sum_Recursive(arr,n-1,sum);
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
	
	------------------Recursive-------------------------
	
	cout<<Count_of_Subset_Sum_Recursive(arr,n,sum)<<endl;
	
	*/
	
	cout<<Count_of_Subset_Sum_DP(arr,n,sum)<<endl;
	
	return 0;
}

