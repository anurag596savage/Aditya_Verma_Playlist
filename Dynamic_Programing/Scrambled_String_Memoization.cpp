#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

map<string,bool>ourMap;

bool Is_Scrambled(string a,string b)
{
	if(a.length()!=b.length())
	{
		return false;
	}
	if(a.length()==0 || b.length()==0)
	{
		return false;
	}
	if(a.compare(b)==0)
	{
		return true;
	}
	if(a.length()<=1)
	{
		return false;
	}
	string temp;
	temp.append(a);
	temp.push_back(' ');
	temp.append(b);
	
	if(ourMap.find(temp)!=ourMap.end())
	{
		return ourMap[temp];
	}
	int flag = false;
	int n = a.length();
	for(int i=1;i<n;i++)
	{
		bool x1 = Is_Scrambled(a.substr(0,i),b.substr(0,i));
		bool x2 = Is_Scrambled(a.substr(i,n-i),b.substr(i,n-i));
		bool y1 = Is_Scrambled(a.substr(0,i),b.substr(n-i,i));
		bool y2 = Is_Scrambled(a.substr(i,n-i),b.substr(0,n-i));
		
		bool op1 = (x1 && x2);
		bool op2 = (y1 && y2);
		if(op1 || op2)
		{
			flag = true;
			break;
		}
	}
	
	return ourMap[temp] = flag;
	
}

int main()
{
	string a,b;
	cin>>a>>b;
	
	cout<<(Is_Scrambled(a,b)?"True":"False")<<endl;
	
	return 0;
}

