#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool dp[10000][10000];

bool Subset_Sum_DP(int arr[],int n,int sum)
{
	
	for(int i=0;i<=sum;i++)
	{
		dp[0][i] = false;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0] = true;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
			}
			else if(arr[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}

bool Subset_Sum_Memoization(int arr[],int n,int sum)
{
	if(sum==0)
	{
		return true;
	}
	if(n==0)
	{
		return false;
	}
	if(dp[n][sum]!=-1)
	{
		return dp[n][sum];
	}
	if(arr[n-1]<=sum)
	{
		return dp[n][sum]=(Subset_Sum_Memoization(arr,n-1,sum-arr[n-1])||Subset_Sum_Memoization(arr,n-1,sum));
	}
	else if(arr[n-1]>sum)
	{
		return dp[n][sum]=Subset_Sum_Memoization(arr,n-1,sum);
	}
}

bool Subset_Sum_Recursive(int arr[],int n,int sum)
{
	if(sum==0)
	{
		return true;
	}
	if(n==0)
	{
		return false;
	}
	
	if(arr[n-1]<=sum)
	{
		return (Subset_Sum_Recursive(arr,n-1,sum-arr[n-1]) || Subset_Sum_Recursive(arr,n-1,sum));
	}
	else if(arr[n-1]>sum)
	{
		return Subset_Sum_Recursive(arr,n-1,sum);
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
	bool ans = Subset_Sum_Recursive(arr,n,sum);
	if(ans)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	*/
	
	/*
	memset(dp,-1,sizeof(dp));
	
	bool ans = Subset_Sum_Memoization(arr,n,sum);
	if(ans)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	*/
	
	string s = Subset_Sum_DP(arr,n-1,sum)?"YES":"NO";
	cout<<s<<endl;
	
	return 0;
}

