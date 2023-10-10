#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> str2st(string str){
	stack<int> t;
	for(int i=0; i<str.size();i++)
	{
		t.push(str[i]-48);
	}
	return t;
}
int main()
{
	stack<int> a;
	stack<int> b;
	stack<int> result;
	string so1, so2;
	cin >> so1 >> so2;
	a = str2st(so1);
	b = str2st(so2);
	int mem = 0, s;
	while(!a.empty() || !b.empty())
	{
		if (!a.empty() && !b.empty())
		{
			s=a.top() + b.top() + mem;
			if (s>=10)
			{
				mem=1;
				s%=10;
			}
			else
			{
				mem=0;
			}
			a.pop();
			b.pop();
		}else if (!a.empty() && b.empty())
		{
			s=a.top() + mem;
			if (s>=10)
			{
				mem=1;
				s%=10;
			}else
			{
				mem=0;
			}
			a.pop();
		}else if (a.empty() && !b.empty())
		{
			s=b.top() + mem;
			if (s>=10)
			{
				mem=1;
				s%=10;
			}else
			{
				mem=0;
			}
			b.pop();
		}
		result.push(s);
	}
	if (mem == 1){
		result.push(mem);	
	}
	while(!result.empty()){
		cout << result.top();
		result.pop();
	}
	cout << endl;
	return 0;
}