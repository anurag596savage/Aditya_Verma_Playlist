#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> Next_Smaller_Right(int* arr,int n)
{
	stack<int>s;
	vector<int>v;
	
	for(int i=n-1;i>=0;i--)
	{
		if(s.empty())
		{
			v.push_back(-1);
		}
		else if(!s.empty() && arr[i]>s.top())
		{
			v.push_back(s.top());
		}
		else
		{
			while(!s.empty() && arr[i]<=s.top())
			{
				s.pop();
			}
			if(s.empty())
			{
				v.push_back(-1);
			}
			else if(arr[i]>s.top())
			{
				v.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	
	reverse(v.begin(),v.end());
	return v;
}

int main()
{
	int n;
	cin>>n;
	
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	vector<int> ans = Next_Smaller_Right(arr,n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	
	return 0;
}

