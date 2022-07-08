#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int arr[1000][1000];

int Knapsack_DP(int wt[],int val[],int n,int W)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(i==0 || j==0)
			{
				arr[i][j] = 0;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(wt[i-1]<=j)
			{
				arr[i][j] = max(val[i-1]+arr[i-1][j-wt[i-1]],arr[n-1][j]);
			}
			else if(wt[i-1]>j)
			{
				arr[i][j] = arr[i-1][j];
			}
		}
	}
	
	return arr[n][W];
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
	
	cout<<Knapsack_DP(wt,val,n,W)<<endl;
	
	return 0;
}

