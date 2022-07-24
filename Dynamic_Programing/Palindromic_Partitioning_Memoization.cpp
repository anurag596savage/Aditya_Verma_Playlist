#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];

bool is_Palindrome(string s,int start,int end)
{
	int i=start,j=end;
	while(i<j)
	{
		if(s[i]==s[j])
		{
			i++;
			j--;
		}
		else
		{
			return false;
		}
	}
	
	return true;
}

int Palindromic_Partitioning(string s,int start,int end)
{
	if(start>=end)
	{
		return 0;
	}
	if(is_Palindrome(s,start,end))
	{
		return 0;
	}
	
	int ans = INT_MAX;
	
	for(int k=start;k<end;k++)
	{
		int left,right;
		if(dp[start][k]!=-1)
		{
			left = dp[start][k];
		}
		else
		{
			left = Palindromic_Partitioning(s,start,k);
			dp[start][k] = left;
		}
		
		if(dp[k+1][end]!=-1)
		{
			right = dp[k+1][end];
		}
		else
		{
			right = Palindromic_Partitioning(s,k+1,end);
			dp[k+1][end] = right;
		}
		
		int current_ans = left+right+1;
		ans = min(ans,current_ans);
	}
	
	return ans;
}

int main()
{
	string s;
	cin>>s;
	
	memset(dp,-1,sizeof(dp));
	
	cout<<Palindromic_Partitioning(s,0,s.length()-1);
	
	return 0;
}

