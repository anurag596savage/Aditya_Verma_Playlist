#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Count_Target_Sum(int arr[],int n,int k)
{
	int sum = accumulate(arr,arr+n,0);
	int new_sum = (sum+k)/2;
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

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	
	cout<<Count_Target_Sum(arr,n,k)<<endl;
	
	return 0;
}

