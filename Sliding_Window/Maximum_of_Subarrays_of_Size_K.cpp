#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> Maximum_of_Subarrays_of_Size_K(int* arr,int n,int k)
{
	vector<int>ans;
	
	deque<int>q;
	int i=0,j=0;
	while(j<n)
	{
		if(q.empty())
		{
			q.push_back(arr[j]);
		}
		else
		{
			while(!q.empty() && arr[j]>=q.back())
			{
				q.pop_back();
			}
			q.push_back(arr[j]);
		}
		if(j-i+1<k)
		{
			j++;
		}
		else if(j-i+1==k)
		{
			ans.push_back(q.front());
			if(q.front()==arr[i])
			{
				q.pop_front();
			}
			i++;
			j++;
		}
	}
	
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
	
	int k;
	cin>>k;
	
	vector<int>v = Maximum_of_Subarrays_of_Size_K(arr,n,k);
	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}