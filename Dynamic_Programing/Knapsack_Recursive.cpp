#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Knapsack_Recursive(int wt[],int val[],int n,int W)
{
	// Base Condition
	
	if(n==0 || W==0)
	{
		return 0;
	}
	
	// Choice Diagram
	
	if(wt[n-1]<=W)
	{
		return max(val[n-1]+Knapsack_Recursive(wt,val,n-1,W-wt[n-1]),Knapsack_Recursive(wt,val,n-1,W));
	}
	else if(wt[n-1]>W)
	{
		return Knapsack_Recursive(wt,val,n-1,W);
	}
}

int main()
{
	int n;
	cin>>n;
	
	int wt[n],val[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	int W;
	cin>>W;
	
	cout<<Knapsack_Recursive(wt,val,n,W)<<endl;
	
	return 0;
}

