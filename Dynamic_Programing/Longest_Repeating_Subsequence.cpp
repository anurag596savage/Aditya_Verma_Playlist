#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Longest_Repeating_Subsequence(string s,int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][i] = 0;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==s[j-1] && i!=j)
			{
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	return dp[n][n];
}

void Print_Longest_Repeating_Subsequence(string s,int n)
{
	string ans="";
	int i=n,j=n;
	while(i>0 && j>0)
	{
		if(s[i-1]==s[j-1] && i!=j)
		{
			ans.push_back(s[i-1]);
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
	
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}

int main()
{
	string s;
	cin>>s;
	
	cout<<Longest_Repeating_Subsequence(s,s.length())<<endl;
	
	Print_Longest_Repeating_Subsequence(s,s.length());
	
	return 0;
}

