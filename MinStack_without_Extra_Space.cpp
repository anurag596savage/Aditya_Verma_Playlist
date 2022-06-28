#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class MinStack
{
	private:
	
	stack<int>s;
	int minElement;
	
	public:
	
	void push_element(int x)
	{
		if(s.empty())
		{
			s.push(x);
			minElement = x;
		}
		else
		{
			if(x>=minElement)
			{
				s.push(x);
			}
			else if(x<minElement)
			{
				s.push(2*x-minElement);
				minElement = x;
			}
		}
	}
	
	int getMin()
	{
		if(s.empty())
		{
			return -1;
		}
		return minElement;
	}
	
	void pop_element()
	{
		if(s.empty())
		{
			return;
		}
		if(s.top()>=minElement)
		{
			s.pop();
		}
		else if(s.top()<minElement)
		{
			minElement = 2*minElement-s.top();
			s.pop();
		}
	}
	
	int top_element()
	{
		if(s.empty())
		{
			return -1;
		}
		if(s.top()>=minElement)
		{
			return s.top();
		}
		else
		{
			return minElement;
		}
	}	
};

int main()
{
	MinStack abc;
	abc.push_element(5);
	abc.push_element(4);
	cout<<"Top Element : "<<abc.top_element()<<endl; // 4
	abc.pop_element();
	abc.push_element(3);
	abc.push_element(7);
	cout<<"Min Element : "<<abc.getMin()<<endl; // 3
	abc.pop_element();
	cout<<"Top Element : "<<abc.top_element()<<endl; // 3
	abc.push_element(2);
	abc.push_element(1);
	cout<<"Min Element : "<<abc.getMin()<<endl; // 1
	
	return 0;
}

