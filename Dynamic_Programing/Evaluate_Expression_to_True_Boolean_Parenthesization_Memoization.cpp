#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

map<string,int>ourMap;

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
	
	string current = to_string(i);
	current.append(" ");
	current.append(to_string(j));
	current.append(to_string(isTrue));
	
	if(ourMap.find(current)!=ourMap.end())
	{
		return ourMap[current];
	}
	
	int ans = 0;
	
	for(int k=i+1;k<j;k=k+2)
	{
		int lTrue = Count_Ways(s,i,k-1,1);
		int lFalse = Count_Ways(s,i,k-1,0);
		int rTrue = Count_Ways(s,k+1,j,1);
		int rFalse = Count_Ways(s,k+1,j,0);
		
		if(s[k]=='&')
		{
			if(isTrue)
			{
				ans += lTrue*rTrue;
			}
			else
			{
				ans += lTrue*rFalse+lFalse*rTrue+lFalse*rFalse;
			}
		}
		else if(s[k]=='|')
		{
			if(isTrue)
			{
				ans += lTrue*rTrue+lFalse*rTrue+lTrue*rFalse;
			}
			else
			{
				ans += lFalse*rFalse;
			}
		}
		else if(s[k]=='^')
		{
			if(isTrue)
			{
				ans += lTrue*rFalse+lFalse*rTrue;
			}
			else
			{
				ans += lTrue*rTrue+lFalse*rFalse;
			}
		}
	}
	
	return ourMap[current]=ans;
	
}

int main()
{
	string s;
	cin>>s;
	
	cout<<Count_Ways(s,0,s.length()-1,1)<<endl;
	
	return 0;
}

