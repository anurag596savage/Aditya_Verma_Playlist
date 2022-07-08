#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int arr[1000][1000];

int Knapsack_Memoization(int wt[],int val[],int n,int W)
{
	if(n==0 || W==0)
	{
		return 0;
	}
	
	if(arr[n][W]!=-1)
	{
		return arr[n][W];
	}
	
	if(wt[n-1]<=W)
	{
		return arr[n][W] = max(val[n-1]+Knapsack_Memoization(wt,val,n-1,W-wt[n-1]),Knapsack_Memoization(wt,val,n-1,W));
	}
	else if(wt[n-1]>W)
	{
		return arr[n][W] = Knapsack_Memoization(wt,val,n-1,W);
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
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			arr[i][j] = -1;
		}
	}
	
	cout<<Knapsack_Memoization(wt,val,n,W)<<endl;
	
	return 0;
}

