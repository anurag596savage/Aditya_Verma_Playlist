#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Count_Ways(string s,int i,int j,int isTrue)
{
	if(i>j)
	{
		return 0;
	}
	if(i==j)
	{
		if(isTrue)
		{
			return s[i]=='T';
		}
		else
		{
			return s[i]=='F';
		}
	}
	int ans = 0;
	for(int k=i+1;k<j;k=k+2)
	{
		int leftTrue = Count_Ways(s,i,k-1,1);
		int leftFalse = Count_Ways(s,i,k-1,0);
		int rightTrue = Count_Ways(s,k+1,j,1);
		int rightFalse = Count_Ways(s,k+1,j,0);
		
		if(s[k]=='&')
		{
			if(isTrue==1)
			{
				ans += leftTrue*rightTrue;
			}
			else
			{
				ans += leftFalse*rightFalse+leftTrue*rightFalse+leftFalse*rightTrue;
			}
	
		}
		
		else if(s[k]=='|')
		{
			if(isTrue==1)
			{
				ans += leftTrue*rightTrue+leftTrue*rightFalse+leftFalse*rightTrue;
			}
			else
			{
				ans += leftFalse*rightFalse;	
			}
		}
		else
		{
			if(isTrue==1)
			{
				ans += leftFalse*rightTrue+leftTrue*rightFalse;
			}
			else
			{
				ans += leftTrue*rightTrue+leftFalse*rightFalse;
			}
		} 
	}
	
	return ans;
}

int main()
{
	string s;
	cin>>s;
	
	cout<<Count_Ways(s,0,s.length()-1,1);
	
	return 0;
}

