#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Count_Occurences_of_Anagram(string a,string b)
{
	unordered_map<char,int>ourMap;
	int k=0;
	for(int i=0;i<b.length();i++)
	{
		ourMap[b[i]]++;
		k++;
	}
	int count = ourMap.size();
	int ans = 0;
	int i=0,j=0;
	while(j<a.length())
	{
		if(ourMap.count(a[i])>0)
		{
			ourMap[a[j]]--;
			if(ourMap[a[j]]==0)
			{
				count--;
			}
		}
		if(j-i+1<k)
		{
			j++;
		}
		else if(j-i+1==k)
		{
			if(count==0)
			{
				ans++;
			}
			if(ourMap.count(a[i])>0)
			{
				ourMap[a[i]]++;
				if(ourMap[a[i]]==1)
				{
					count++;
				}
			}
			
			i++;
			j++;
		}
		
	}
	
	return ans;
}

int main()
{
	string a;
	cin>>a;
	string b;
	cin>>b;
	cout<<Count_Occurences_of_Anagram(a,b)<<endl; 
	return 0;
}

