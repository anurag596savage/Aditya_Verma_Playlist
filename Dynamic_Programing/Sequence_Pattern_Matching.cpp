#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1000][1000];

bool Sequence_Pattern_Matching(string x,string y,int m,int n)
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
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	
	if(dp[m][n]==min(m,n))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string x,y;
	cin>>x>>y;
	
	string res = (Sequence_Pattern_Matching(x,y,x.length(),y.length()))? "YES" :"NO";
	cout<<res<<endl;
	
	return 0;
}

