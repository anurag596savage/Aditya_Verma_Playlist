#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> First_Negative_No_in_Window_of_Size_K(int* arr,int n,int k)
{
	queue<int>q;
	vector<int>ans;
	
	int i=0,j=0;
	while(j<n)
	{
		if(arr[j]<0)
		{
			q.push(arr[j]);
		}
		
		if(j-i+1<k)
		{
			j++;
		}
		else if(j-i+1==k)
		{
			if(q.empty())
			{
				ans.push_back(0);
			}
			else
			{
				ans.push_back(q.front());
			}
			if(!q.empty() && arr[i]==q.front())
			{
				q.pop();
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
	vector<int> res = First_Negative_No_in_Window_of_Size_K(arr,n,k);
	
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

