#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];

int Minimum_Count(int f,int e)
{
	if(f==1 || f==0)
	{
		return f;
	}
	if(e==1)
	{
		return f;
	}
	if(e==0)
	{
		return 0;
	}
	if(dp[f][e]!=-1)
	{
		return dp[f][e];
	}
	int ans = INT_MAX;
	for(int i=1;i<=f;i++)
	{
		int x;
		if(dp[f-1][e-1]==-1)
		{
			x = Minimum_Count(f-1,e-1);
			dp[f-1][e-1] = x;
		}
		else
		{
			x = dp[f-1][e-1];
		}
		
		int y;
		if(dp[f-i][e]==-1)
		{
			y = Minimum_Count(f-i,e);
			dp[f-i][e] = y;
		}
		else
		{
			y = dp[f-i][e];
		}
		
		int temp = max(x,y);
		ans = min(ans,temp);
	}
	
	return ans;
}

int main()
{
	int f,e;
	cin>>f>>e;
	
	memset(dp,-1,sizeof(dp));
	
	cout<<Minimum_Count(f,e)<<endl;
	
	return 0;
}

