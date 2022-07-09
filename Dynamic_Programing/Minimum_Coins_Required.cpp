#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Minimum_Coins_Required_DP(int arr[],int n,int sum)
{
	for(int i=0;i<=sum;i++)
	{
		dp[0][i] = INT_MAX-1;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0] = 0;
	}
	for(int i=1;i<=sum;i++)
	{
		if(i%arr[0]==0)
		{
			dp[1][i] = i/arr[0];
		}
		else
		{
			dp[1][i] = INT_MAX-1;
		}
	}
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j] = min(1+dp[i][j-arr[i-1]],dp[i-1][j]);
			}
			else if(arr[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}

int Minimum_Coins_Required_Recursive(int arr[],int n,int sum)
{
	if(sum==0)
	{
		return 0;
	}
	if(n==0)
	{
		return INT_MAX-1;
	}
	if(n==1)
	{
		if(sum%arr[n-1]==0)
		{
			return sum/arr[n-1];
		}
		else
		{
			return INT_MAX-1;
		}
	}
	
	if(arr[n-1]<=sum)
	{
		return min(1+Minimum_Coins_Required_Recursive(arr,n,sum-arr[n-1]),
			Minimum_Coins_Required_Recursive(arr,n-1,sum));
	}
	else if(arr[n-1]>sum)
	{
		return Minimum_Coins_Required_Recursive(arr,n-1,sum);
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
	
	------------------------Recursive----------------------
	
	cout<<Minimum_Coins_Required_Recursive(arr,n,sum)<<endl;
	
	
	*/
	
	cout<<Minimum_Coins_Required_DP(arr,n,sum)<<endl;
	
	return 0;
}

