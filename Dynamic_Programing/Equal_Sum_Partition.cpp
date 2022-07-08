#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];


bool Subset_Sum(int arr[],int n,int sum)
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
				dp[i][j] = (dp[i-1][j] || dp[i][j-arr[i-1]]);
			}
			else if(arr[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}

bool Equal_Sum_Partition(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
	}
	if(sum%2!=0)
	{
		return false;
	}
	else
	{
		return Subset_Sum(arr,n,sum/2);
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
	
	cout<<(Equal_Sum_Partition(arr,n)?"YES":"NO")<<endl;
	
	return 0;
}

