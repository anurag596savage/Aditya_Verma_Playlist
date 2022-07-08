#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Count_of_Subsets_with_difference_2(int arr[],int n,int difference)
{
	int sum = accumulate(arr,arr+n,0);
	int new_sum = (sum+difference)/2;
	
	for(int i=0;i<=new_sum;i++)
	{
		dp[0][i] = 0;
	}
	
	for(int i=0;i<=n;i++)
	{
		dp[i][0] = 1;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=new_sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
			}
			else if(arr[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][new_sum];
}

int Count_of_Subsets_with_difference_1(int arr[],int n,int difference)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
	}
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
	
	int count = 0;
	for(int i=0;i<=sum/2;i++)
	{
		if(sum-2*dp[n][i]==difference)
		{
			count += dp[n][i];
		}
	}
	
	return count;
	
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
	
	int difference;
	cin>>difference;
	
	/*
	
	cout<<Count_of_Subsets_with_difference_1(arr,n,difference)<<endl;
	
	*/
	
	cout<<Count_of_Subsets_with_difference_2(arr,n,difference)<<endl;
	
	return 0;
}

