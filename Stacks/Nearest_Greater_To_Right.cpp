#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> Next_Greater_Right(int* arr,int n)
{
	stack<int>s;
	vector<int>ans;
	for(int i=n-1;i>=0;i--)
	{
		if(s.empty())
		{
			ans.push_back(-1);
		}
		else if(!s.empty() && arr[i]<s.top())
		{
			ans.push_back(s.top());
		}
		else if(!s.empty() && arr[i]>=s.top())
		{
			while(!s.empty() && arr[i]>=s.top())
			{
				s.pop();
			}
			if(s.empty())
			{
				ans.push_back(-1);
			}
			else if(s.top()>arr[i])
			{
				ans.push_back(s.top());
			}
		}
		
		s.push(arr[i]);
	}
	
	reverse(ans.begin(),ans.end());
	
	return ans;
	
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
	
	vector<int> ans = Next_Greater_Right(arr,n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

