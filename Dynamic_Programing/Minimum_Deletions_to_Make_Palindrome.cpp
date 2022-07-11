#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

int Minimum_Deletions_to_Make_Palindrome(string x,int n)
{
	string y = x;
	reverse(y.begin(),y.end());
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	int deletions = x.length()-dp[n][n];
	return deletions;
}

int main()
{
	string s;
	cin>>s;
	
	cout<<Minimum_Deletions_to_Make_Palindrome(s,s.length())<<endl;
	
	return 0;
}

