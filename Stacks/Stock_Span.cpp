#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> Stock_Span(int* arr,int n)
{
	vector<int>v;
	stack<int>s;
	
	for(int i=0;i<n;i++)
	{
		if(s.empty())
		{
			v.push_back(i+1);
		}
		else if(!s.empty() && arr[i]<=arr[s.top()])
		{
			v.push_back(i-s.top());
		}
		else
		{
			while(!s.empty() && arr[i]>arr[s.top()])
			{
				s.pop();
			}
			if(s.empty())
			{
				v.push_back(i+1);
			}
			else if(!s.empty() && arr[i]<=arr[s.top()])
			{
				v.push_back(i-s.top());
			}
		}
		
		s.push(i);
	}
	
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
	
	vector<int>ans = Stock_Span(arr,n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

