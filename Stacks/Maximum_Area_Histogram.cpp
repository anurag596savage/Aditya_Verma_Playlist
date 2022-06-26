#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Max_Area_Histogram(int* arr,int n)
{
	stack<int>s;
	vector<int>lwidth;
	vector<int>rwidth;
	for(int i=0;i<n;i++)
	{
		if(s.empty())
		{
			lwidth.push_back(-1);
		}
		else if(!s.empty() && arr[i]>arr[s.top()])
		{
			lwidth.push_back(s.top());
		}
		else
		{
			while(!s.empty() && arr[i]<=arr[s.top()])
			{
				s.pop();
			}
			if(s.empty())
			{
				lwidth.push_back(-1);
			}
			else if(!s.empty() && arr[i]>arr[s.top()])
			{
				lwidth.push_back(s.top());
			}
		}
		s.push(i);
	}
	while(!s.empty())
	{
		s.pop();
	}
	for(int i=n-1;i>=0;i--)
	{
		if(s.empty())
		{
			rwidth.push_back(n);
		}
		else if(!s.empty() && arr[i]>arr[s.top()])
		{
			rwidth.push_back(s.top());
		}
		else
		{
			while(!s.empty() && arr[i]<=arr[s.top()])
			{
				s.pop();
			}
			if(s.empty())
			{
				rwidth.push_back(n);
			}
			else if(!s.empty() && arr[i]>arr[s.top()])
			{
				rwidth.push_back(s.top());
			}
		}
		s.push(i);
	
	}
	
	reverse(rwidth.begin(),rwidth.end());
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
		ans.push_back((rwidth[i]-lwidth[i]-1)*arr[i]);
	}
	int res = *max_element(ans.begin(),ans.end());
	return res;
	
	
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
	
	int res = Max_Area_Histogram(arr,n);
	cout<<res<<endl;
	
	return 0;
}

