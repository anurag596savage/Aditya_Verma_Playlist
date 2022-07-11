#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

void Print_LCS(string x,string y,int m,int n)
{
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
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else 
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string s="";
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(x[i-1]==y[j-1])
		{
			s.push_back(x[i-1]);
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}

int main()
{
	string x,y;
	cin>>x>>y;
	
	Print_LCS(x,y,x.length(),y.length());
	
	return 0;
}

