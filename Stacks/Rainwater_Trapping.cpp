#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Rainwater_Trapping(vector<int>v)
{
	vector<int>lmax(v.size());
	lmax[0] = v[0];
	for(int i=1;i<v.size();i++)
	{
		lmax[i] = max(v[i],lmax[i-1]);
	}
	vector<int>rmax(v.size());
	rmax[v.size()-1] = v[v.size()-1];
	for(int i=v.size()-2;i>=0;i--)
	{
		rmax[i] = max(v[i],rmax[i+1]);
	}
	
	vector<int>water(v.size());
	for(int i=0;i<v.size();i++)
	{
		water[i] = min(lmax[i],rmax[i])-v[i];
	}
	int ans = accumulate(water.begin(),water.end(),0);
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	vector<int>v(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	cout<<Rainwater_Trapping(v)<<endl;
	
	return 0;
}

