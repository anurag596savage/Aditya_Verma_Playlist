#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool dp[1000][1000];

int Minimum_Subset_Sum_Difference(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
	}
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
	
	vector<int>v;
	for(int i=0;i<=sum/2;i++)
	{
		if(dp[n][i]==true)
		{
			v.push_back(i);
		}
	}
	int ans = INT_MAX;
	for(int i=0;i<v.size();i++)
	{
		ans = min(ans,sum-2*v[i]);
	}
	
	return ans;
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
	cout<<Minimum_Subset_Sum_Difference(arr,n)<<endl;
	
	return 0;
}

