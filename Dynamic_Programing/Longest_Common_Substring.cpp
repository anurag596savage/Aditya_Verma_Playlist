#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Longest_Common_Substring_DP(string x,string y,int m,int n)
{
	int ans = 0;;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 0;
			}
			
			ans = max(ans,dp[i][j]);
		}
	}
	
	return ans;
}

int Longest_Common_Substring_Recursive(string x,string y,int m,int n,int count)
{
	if(m==0 || n==0)
	{
		return count;
	}
	if(x[m-1]==y[n-1])
	{
		count = Longest_Common_Substring_Recursive(x,y,m-1,n-1,count+1);
	}
	int count1 = Longest_Common_Substring_Recursive(x,y,m-1,n,0);
	int count2 = Longest_Common_Substring_Recursive(x,y,m,n-1,0);
	
	return max({count,count1,count2});
}

int main()
{
	string x,y;
	cin>>x>>y;
	
	cout<<Longest_Common_Substring_DP(x,y,x.length(),y.length())<<endl;
	
	/*
	
	---------------------------Recursive---------------------------------------
	
	cout<<Longest_Common_Substring_Recursive(x,y,x.length(),y.length(),0)<<endl;
	
	
	*/
	
	
	return 0;
}

