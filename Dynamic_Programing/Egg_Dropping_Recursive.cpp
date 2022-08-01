#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Minimum_Count(int f,int e)
{
	if(f==0 || f==1)
	{
		return f;
	}
	if(e==1)
	{
		return f;
	}
	if(e==0)
	{
		return 0;
	}
	
	int ans = INT_MAX;
	for(int i=1;i<=f;i++)
	{
		int temp = max(Minimum_Count(f-1,e-1),Minimum_Count(f-i,e));
		ans = min(ans,temp);
	}
	
	return ans;
}

int main()
{
	int f,e;
	cin>>f>>e;
	
	cout<<Minimum_Count(f,e)<<endl;
	
	return 0;
}

