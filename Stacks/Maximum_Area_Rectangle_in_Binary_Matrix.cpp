#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007


int Maximum_Area_Histogram(vector<int>v)
{
	stack<int>s;
	
	vector<int>l;
	vector<int>r;
	
	for(int i=0;i<v.size();i++)
	{
		if(s.empty())
		{
			l.push_back(-1);
		}
		else if(!s.empty() && v[i]>v[s.top()])
		{
			l.push_back(s.top());
		}
		else
		{
			while(!s.empty() && v[i]<=v[s.top()])
			{
				s.pop();
			}
			if(s.empty())
			{
				l.push_back(-1);
			}
			else if(!s.empty() && v[i]>v[s.top()])
			{
				l.push_back(s.top());
			}
		}
		s.push(i);
	}
	
	while(!s.empty())
	{
		s.pop();
	}
	
	for(int i=v.size()-1;i>=0;i--)
	{
		if(s.empty())
		{
			r.push_back(v.size());
		}
		else if(!s.empty() && v[i]>v[s.top()])
		{
			r.push_back(s.top());
		}
		else
		{
			while(!s.empty() && v[i]<=v[s.top()])
			{
				s.pop();
			}
			if(s.empty())
			{
				r.push_back(v.size());
			}
			else if(!s.empty() && v[i]>v[s.top()])
			{
				r.push_back(s.top());
			}
		}
		s.push(i);
	}
	
	reverse(r.begin(),r.end());
	
	vector<int>width;
	
	for(int i=0;i<v.size();i++)
	{
		width.push_back(r[i]-l[i]-1);
	}
	vector<int>res;
	for(int i=0;i<v.size();i++)
	{
		res.push_back(width[i]*v[i]);
	}
	
	int ans = *max_element(res.begin(),res.end());
	
	return ans;
	
}

int Maximum_Area_Rectangle_in_Binary_Matrix(vector<vector<int>> arr)
{
	vector<int>hist;
	for(int i=0;i<arr[0].size();i++)
	{
		hist.push_back(arr[0][i]);
	}
	
	int ans = Maximum_Area_Histogram(hist);
	
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[0].size();j++)
		{
			if(arr[i][j]==0)
			{
				hist[j] = 0;
			}
			else
			{
				hist[j] = (hist[j]+arr[i][j]);
			}
			
		}
		
		int possible_ans = Maximum_Area_Histogram(hist);
		ans = max(ans,possible_ans);
	}
	
	return ans;
}

int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int>>arr;
	for(int i=0;i<m;i++)
	{
		vector<int>v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		arr.push_back(v);
	}
	
	int ans = Maximum_Area_Rectangle_in_Binary_Matrix(arr);
	cout<<ans<<endl;
	
	return 0;
}

