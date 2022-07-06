#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Largest_Subarray_of_Sum(int* arr,int n,int k)
{
	int ans=0;
	int sum=0,i=0,j=0;
	
	while(j<n)
	{
		sum += arr[j];
		
		if(sum<k)
		{
			j++;
		}
		
		else if(sum==k)
		{
			ans = max(ans,j-i+1);
			j++;
		}
		
		else if(sum>k)
		{
			while(sum>k)
			{
				sum = sum-arr[i];
				i++;
			}
			if(sum==k)
			{
				ans = max(ans,j-i+1);
			}
			if(sum<k)
			{
				j++;
			}
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
	
	cout<<Largest_Subarray_of_Sum(arr,n,k)<<endl;
	
	return 0;
}

