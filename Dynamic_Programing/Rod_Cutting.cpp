#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Rod_Cutting_DP(int price[],int length[],int n,int size)
{
	for(int i=0;i<=size;i++)
	{
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=size;j++)
		{
			if(length[i-1]<=j)
			{
				dp[i][j] = max(dp[i-1][j],price[i-1]+dp[i][j-length[i-1]]);
			}
			else if(length[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][size];
}

int Rod_Cutting_Recursive(int price[],int length[],int n,int size)
{
	if(n==0 || size==0)
	{
		return 0;
	}
	if(length[n-1]<=size)
	{
		return max(price[n-1]+Rod_Cutting_Recursive(price,length,n,size-length[n-1]),
			Rod_Cutting_Recursive(price,length,n-1,size));
	}
	else if(length[n-1]>size)
	{
		return Rod_Cutting_Recursive(price,length,n-1,size);
	}
}

int main()
{
	int n;
	cin>>n;
	
	int price[n];
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	
	int length[n];
	for(int i=0;i<n;i++)
	{
		length[i] = i+1;
	}
	
	int size;
	cin>>size;
	
	/*
	------------------Recursive---------------------------
	
	cout<<Rod_Cutting_Recursive(price,length,n,size)<<endl;
	
	*/
	
	cout<<Rod_Cutting_DP(price,length,n,size)<<endl;
	
	return 0;
}

