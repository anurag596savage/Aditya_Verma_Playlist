#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Longest_Substring_with_K_Unique_Characters(string s,int k)
{
	int ans = 0;
	int i=0,j=0;
	unordered_map<char,int>ourMap;
	while(j<s.length())
	{
		ourMap[s[j]]++;
		
		if(ourMap.size()<k)
		{
			j++;
		}
		else if(ourMap.size()==k)
		{
			ans = max(ans,j-i+1);
			j++;
		}
		else if(ourMap.size()>k)
		{
			while(ourMap.size()>k)
			{
				ourMap[s[i]]--;
				if(ourMap[s[i]]==0)
				{
					ourMap.erase(s[i]);
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
	
	int k;
	cin>>k;
	
	cout<<Longest_Substring_with_K_Unique_Characters(s,k)<<endl;
	
	return 0;
}

