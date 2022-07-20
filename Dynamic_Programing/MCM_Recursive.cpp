#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Minimum_Cost_for_Matrix_Multiplication(int* arr,int n,int i,int j)
{
	if(i>=j)
	{
		return 0;
	}
	int ans = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int current_ans = Minimum_Cost_for_Matrix_Multiplication(arr,n,i,k)+
		Minimum_Cost_for_Matrix_Multiplication(arr,n,k+1,j)+arr[i-1]*arr[k]*arr[j];
		
		ans = min(ans,current_ans);
	}
	
	return ans;
}

int Minimum_Cost_for_Matrix_Multiplication(int* arr,int n)
{
	return Minimum_Cost_for_Matrix_Multiplication(arr,n,1,n-1);
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
	
	cout<<Minimum_Cost_for_Matrix_Multiplication(arr,n)<<endl;
	
	return 0;
}

