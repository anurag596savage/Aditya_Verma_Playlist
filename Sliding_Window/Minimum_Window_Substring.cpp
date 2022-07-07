#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Minimum_Window_Substring(string s,string t)
{
	int ans=INT_MAX;
	int i=0,j=0;
	unordered_map<char,int>ourMap;
	for(int i=0;i<t.length();i++)
	{
		ourMap[t[i]]++;
	}
	int count = ourMap.size();
	
	while(j<s.length())
	{
		if(ourMap.count(s[j])>0)
		{
			ourMap[s[j]]--;
			if(ourMap[s[j]]==0)
			{
				count--;
			}
		}
		
		if(count>0)
		{
			j++;
		}
		else if(count==0)
		{
			while(count==0)
			{
				ans = min(ans,j-i+1);
				if(ourMap.count(s[i])>0)
				{
					ourMap[s[i]]++;
					if(ourMap[s[i]]==1)
					{
						count++;
					}
				}
				i++;
			}
			j++;
		}
	}
	
	return ans;
}

int main()
{
	string s;
	cin>>s;
	
	string t;
	cin>>t;
	
	cout<<Minimum_Window_Substring(s,t)<<endl;
	
	return 0;
}

