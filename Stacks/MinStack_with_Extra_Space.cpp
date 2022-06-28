#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class MinStack
{
	private:
	
	stack<int>s;
	stack<int>ss;
	
	public:
	
	void push_element(int x)
	{
		s.push(x);
		if(ss.empty() || ss.top()>=x)
		{
			ss.push(x);
		}
	}
	
	int pop_element()
	{
		if(s.empty())
		{
			return -1;
		}
		int x = s.top();
		s.pop();
		if(ss.top()==x)
		{
			ss.pop();
		}
		return x;
	}
	
	int min_element()
	{
		if(ss.empty())
		{
			return -1;
		}
		
		return ss.top();
	}	
};

int main()
{
	MinStack abc;
	
	abc.push_element(18);
	abc.push_element(19);
	cout<<"Element removed : "<<abc.pop_element()<<endl; // 19
	abc.push_element(29);
	abc.push_element(15);
	cout<<"Min Element : "<<abc.min_element()<<endl; // 15
	abc.push_element(16);
	abc.push_element(15);
	cout<<"Element removed : "<<abc.pop_element()<<endl; // 15
	cout<<"Element removed : "<<abc.pop_element()<<endl; // 16
	cout<<"Min Element : "<<abc.min_element()<<endl; // 18
	
	return 0;
}

