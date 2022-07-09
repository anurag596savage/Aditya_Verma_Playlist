#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int arr[1000][1000];

int LCS(string x,string y,int m,int n)
{
	if(m==0 || n==0)
	{
		return 0;
	}
	if(arr[m][n]!=-1)
	{
		return arr[m][n];
	}
	
	if(x[m-1]==y[n-1])
	{
		return arr[m][n] = 1+LCS(x,y,m-1,n-1);
	}
	else
	{
		return arr[m][n] = max(LCS(x,y,m-1,n),LCS(x,y,m,n-1));
	}
}

int main()
{
	string x,y;
	cin>>x>>y;
	
	memset(arr,-1,sizeof(arr));
	
	cout<<LCS(x,y,x.length(),y.length())<<endl;
	
	return 0;
}

