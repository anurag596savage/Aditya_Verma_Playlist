#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Longest_Substring_without_Repeating_Characters(string s)
{
	int ans = 0;
	unordered_map<char,int>ourMap;
	int i=0,j=0;
	while(j<s.length())
	{
		ourMap[s[j]]++;
		
		if(ourMap.size()==j-i+1)
		{
			ans = max(ans,j-i+1);
			j++;
		}
		else if(ourMap.size()<j-i+1)
		{
			while(ourMap.size()<j-i+1)
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
	
	cout<<Longest_Substring_without_Repeating_Characters(s)<<endl;
	
	return 0;
}

