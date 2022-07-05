#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Maximum_Sum_Subarray_of_Size_K_Brute_Force(int* arr,int n,int k)
{
	int ans = INT_MIN;
	for(int i=0;i<=n-k;i++)
	{
		int current_sum=0;
		for(int j=i;j<i+k;j++)
		{
			current_sum += arr[j];
		}
		ans = max(ans,current_sum);
	}
	return ans;
}

int Maximum_Sum_Subarray_of_Size_K(int* arr,int n,int k)
{
	int ans = INT_MIN;
	int current_sum=0;
	int i=0,j=0;
	while(j<n)
	{
		current_sum += arr[j];
		
		if(j-i+1<k)
		{
			j++;
		}
		else if(j-i+1==k)
		{
			ans = max(current_sum,ans);
			current_sum -= arr[i];
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
	
	cout<<Maximum_Sum_Subarray_of_Size_K_Brute_Force(arr,n,k)<<endl;
	
	cout<<Maximum_Sum_Subarray_of_Size_K(arr,n,k)<<endl;
	return 0;
}

